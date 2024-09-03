#version 330 core
// volumen_rendering fragment shader

#define USE_INTERMEDIATE

in vec2 uv;

uniform vec2 iResolution;
uniform float iTime;
uniform sampler3D textureSampler;

out vec4 color;

// bounding box
const vec3 bbMin = vec3(-0.5F);
const vec3 bbMax = vec3(0.5F);

// additional camera parameters
const float fovy = 58.0F * (3.14159267F / 180.0F); // degrees converted to radians
const float zNear = 0.1F;

// light direction
const vec3 lightDir = vec3(1.0F, 1.0F, 1.0F);

const vec4 lightColor = vec4(1.0F);
const vec4 specularColor = vec4(1.0F);
const float ka = 0.5F;  // ambient contribution
const float kd = 0.5F;  // diffuse contribution
const float ks = 0.7F;  // specular contribution
const float exponent = 50.0F;  // specular exponent (shininess)

// number of maximum raycasting samples per ray
const int sampleNum = 150;

// width of one voxel
const float voxelWidth = 1.0F / 64.0F;

// Colors for the colormap
const vec3 colorNode0 = vec3(0.0F, 0.0F, 1.0F);  // blue
//const vec3 colorNode1 = vec3(1.0F, 1.0F, 1.0F);  // white
const vec3 colorNode1 = vec3(0.0F, 1.0F, 0.0F);  // green
const vec3 colorNode2 = vec3(1.0F, 0.0F, 0.0F);  // red

/**
 *	Samples the volume texture at a given position.
 *
 *	@param texCoord The position one wants to retrieve the sample of (in world coordinates).
 *	@return The sample value at the given position.
 */
float sampleVolume(vec3 texCoord)
{
    return texture(textureSampler, texCoord).r;
}

/**
 *	Evaluates the transfer function for a given sample value
 *
 *	@param value The sample value
 *	@return The color for the given sample value
 */
vec4 transferFunction(float value)
{
    float alpha = value * 0.5F; // value;
    if (value < 0.2F)
        alpha = 0.5F; // 0.0F;

    float t = 0.0F;
    vec3 color0 = colorNode0;
    vec3 color1 = colorNode1;
    if (value < 0.5F)
    {
        t = 2.0F * value;
    }
    else
    {
        t = 2.0F * (value - 0.5F);
        color0 = colorNode1;
        color1 = colorNode2;
    }
    vec4 color;
    color.a = alpha;
    color.rgb = color0 * (1.0F - t) + color1 * t;
    return color;
}

/**
 *	Intersects a ray with the bounding box and returns the intersection points
 *
 * 	@param rayOrig The origin of the ray.
 * 	@param rayDir The direction of the ray.
 *  @param tNear OUT The distance from the ray origin to the first intersection point.
 *  @param tFar OUT The distance from the ray origin to the second intersection point.
 *  @return True if the ray intersects the bounding box, false otherwise.
 */
bool intersectBoundingBox(vec3 rayOrig, vec3 rayDir, out float tNear, out float tFar)
{
    vec3 invR = vec3(1.0F) / rayDir;
    vec3 tbot = invR * (bbMin - rayOrig);
    vec3 ttop = invR * (bbMax - rayOrig);

    vec3 tmin = min(ttop, tbot);
    vec3 tmax = max(ttop, tbot);

    float largestTMin = max(max(tmin.x, tmin.y), max(tmin.x, tmin.z));
    float smallestTMax = min(min(tmax.x, tmax.y), min(tmax.x, tmax.z));

    tNear = largestTMin;
    tFar = smallestTMax;

    return smallestTMax > largestTMin;
}

// *** added functions for lighting along the ray *** //

vec3 gradientCentral(vec3 pos)
{
    // TODO: Insert code here

    return vec3(1.0F, 0.0F, 0.0F); // placeholder value
}

vec3 gradientIntermediate(vec3 pos)
{
    // TODO: Insert code here

    return vec3(1.0F, 0.0F, 0.0F); // placeholder value
}

vec4 lighting(vec4 diffuseColor, vec3 normal, vec3 eyeDir)
{
    // TODO: Insert code here

    return vec4(0.5F, 0.5F, 0.5F, 1.0F); // placeholder value
}

// *** *** //

/**
 *	Correct opacity for the current sampling rate
 *
 *	@param alpha The input opacity.
 *	@param samplingRatio The ratio between current sampling rate and the original one.

 */
float opacityCorrection(float alpha, float samplingRatio)
{
    float a_corrected = 1.0F - pow(1.0F - alpha, samplingRatio);
    return a_corrected;
}

// Choose technique
// TODO: set technique
const int technique = 0; // technique = 0: accumulation, 1: maximum intensity projection, 2: average intensity


/**
 * Accumulation composition
 *
 * @param value The current sample value.
 * @param opacityCorrectionFactor The ratio between current sampling rate and the original one.
 * @param composedColor The blended color (both input and output).
 */
void accumulation(float value, float opacityCorrectionFactor, inout vec4 composedColor)
{
    vec4 color = transferFunction(value);
    color.a = opacityCorrection(color.a, opacityCorrectionFactor);

    // TODO: Implement Front-to-back blending
    composedColor = vec4(0.5F) * value; // placeholder
}

/**
 * Maximum Intensity Projection
 *
 * @param value The current sample value.
 * @param maxIntense The maximum intensity along the ray (both input and output).
 */
void maximumIntensity(float value, inout float maxIntense)
{
    // TODO: Record maximum intensity along the ray.
}

/**
 * Average intensity: summing up intensity along a ray
 *
 * @param value The current sample value.
 * @param sumIntense The summed intensity along the ray (both input and output).
 * @param hitCount The number of ray hits inside the volume (both input and output).
 */
void sumIntensity(float value, inout float sumIntense, inout int hitCount)
{
    // TODO: sum up the intensity along the ray.
}

/**
 * Main Function: Computes the color for the given fragment.
 *
 * @param fragColor OUT The color of the pixel / fragment.
 */
void mainImage(out vec4 fragColor)
{
    // show the lookup table
//    fragColor = texture(lookupTable, uv);
//    return;

    float aspect = iResolution.x / iResolution.y;

    /******************** compute camera parameters ********************/

    // camera movement
    float camSpeed = 0.5F;
    vec3 camPos = 1.5F * vec3(cos(iTime * camSpeed), 0.5F, sin(iTime * camSpeed));
    vec3 camDir = -normalize(camPos);
    vec3 camUp = vec3(0.0F, 1.0F, 0.0F);
    vec3 camRight = normalize(cross(camDir, camUp));
    camUp = normalize(cross(camRight, camDir));

    /************ compute ray direction (OpenGL style) *****************/
    float fovx = 2.0F * atan(tan(fovy / 2.0F) * aspect);

    vec3 uL = (tan(fovx * 0.5F) * zNear) * (-camRight) + (tan(fovy * 0.5F) * zNear) * camUp + camDir * zNear + camPos;
    vec3 lL = (tan(fovx * 0.5F) * zNear) * (-camRight) + (tan(fovy * 0.5F) * zNear) * (-camUp) + camDir * zNear + camPos;
    vec3 uR = (tan(fovx * 0.5F) * zNear) * camRight + (tan(fovy * 0.5F) * zNear) * camUp + camDir * zNear + camPos;
    vec3 lR = (tan(fovx * 0.5F) * zNear) * camRight + (tan(fovy * 0.5F) * zNear) * (-camUp) + camDir * zNear + camPos;

    vec3 targetL = mix(lL, uL, uv.y);
    vec3 targetR = mix(lR, uR, uv.y);
    vec3 target = mix(targetL, targetR, uv.x);

    vec3 rayDir = normalize(target - camPos);

    /******************* test against bounding box ********************/
    float tNear;
    float tFar;
    bool hit = intersectBoundingBox(camPos, rayDir, tNear, tFar);
    vec4 background = vec4(0.0F, 0.0F, 0.0F, 1.0F);

    if (!hit)
    {
        fragColor = background;
        return;
    }

    float rayStepSize = (bbMax.x - bbMin.x) / float(sampleNum);
    vec4 finalColor = vec4(0.0F);
    vec3 finalGradient = vec3(0.0F);
    // ratio between current sampling rate vs. the original sampling rate
    float opacityCorrectionFactor = 1.0F / (float(sampleNum) * voxelWidth);
    /******************** main raycasting loop *******************/

    // For maximum intensity composition
    float maxIntense = 0.0F;

    // For average intensity composition
    float sumIntense = 0.0F;
    int hitCount = 0;

    float t = tNear;
    int i = 0;
    while(t < tFar && i < sampleNum)
    {
        vec3 pos = camPos + t * rayDir;
        // Use normalized volume coordinate
        vec3 texCoord = pos + 0.5F;
        float value = sampleVolume(texCoord);

        if (technique == 0)
            accumulation(value, opacityCorrectionFactor, finalColor);
        else if (technique == 1)
            maximumIntensity(value, maxIntense);
        else if (technique == 2)
            sumIntensity(value, sumIntense, hitCount);
        else
            accumulation(value, opacityCorrectionFactor, finalColor);

        t += rayStepSize;
    }


    // TODO: Determine final color:
    if (technique == 0)
    {
        // TODO: color for accumulation
    }
    else if (technique == 1)
    {
        // TODO: color for max. intensity projection
    }
    else if (technique == 2)
    {
        // TODO: color for average intensity
    }

    fragColor.rgb = mix(background.rgb, finalColor.rgb, finalColor.a);
    fragColor.a = 1.0F;
}

void main()
{
    mainImage(color);
}
