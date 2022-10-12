#version 330 core
// Volume rendering pre-integration fragment shader

in vec2 uv;

uniform vec2 iResolution;
uniform float iTime;
uniform sampler3D textureSampler;
uniform sampler2D lookupTable;

out vec4 color;

// bounding box
const vec3 bbMin = vec3(-0.5, -0.5, -0.5);
const vec3 bbMax = vec3(0.5, 0.5, 0.5);

// additional camera parameters
const float fovy = 45.0;
const float zNear = 0.1;

// number of maximum raycasting samples per ray
const int sampleNum = 100; // 150

// width of one voxel
const float voxelWidth = 1.0 / 64.0;

// epsilon for comparisons
const float EPS = 0.000001;
const float PI = 3.14159267;
const float period = 2.0;
// sigma for the gaussian function
const float sig = 0.4;

// for colormapping
// Define your colors for the colormap
const vec3 colorNode0 = vec3(0, 0, 1);  // blue
// const vec3 colorNode1 = vec3(1, 1, 1); // white
const vec3 colorNode1 = vec3(0, 1, 0); // green
const vec3 colorNode2 = vec3(1, 0, 0);  // red

vec2 csqr( vec2 a )  { return vec2( a.x*a.x - a.y*a.y, 2.*a.x*a.y  ); }

/**
 *	Samples the volume texture at a given position.
 *
 *	@param volumeCoord The position one wants to retrieve the sample of (in world coordinates).
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

    float t = 0.0;
    vec3 color0 = colorNode0;
    vec3 color1 = colorNode1;
    if( value < 0.5 )
    {
        t = 2.0 * value;
    }
    else
    {
        t = 2.0 * (value - 0.5);
        color0 = colorNode1;
        color1 = colorNode2;
     }
    vec4 color;
    color.a = alpha;
    color.rgb = color0 * (1.0 - t) + color1 * t;
    return color;
}

/**
 *	Intersects a ray with the bounding box and returs the intersection points
 *
 * 	@param rayOrig The origin of the ray
 * 	@param rayDir The direction of the ray
 *  @param tNear OUT: The distance from the ray origin to the first intersection point
 *	@param tFar OUT: The distance from the ray origin to the second intersection point
 *	@return True if the ray intersects the bounding box, false otherwise.
 */
bool intersectBoundingBox(vec3 rayOrig, vec3 rayDir, out float tNear, out float tFar)
{
    vec3 invR = vec3(1.0) / rayDir;
    vec3 tbot = invR * (bbMin - rayOrig);
    vec3 ttop = invR * (bbMax - rayOrig);

    vec3 tmin = min(ttop, tbot);
    vec3 tmax = max(ttop, tbot);

    float largestTMin = max(max(tmin.x, tmin.y), max(tmin.x, tmin.z));
    float smallestTMax = min(min(tmax.x, tmax.y), min(tmax.x, tmax.z));

    tNear = largestTMin;
    tFar = smallestTMax;

    return (smallestTMax > largestTMin);
}

/**
 *	Correct opacity for the current sampling rate
 *
 *	@param alpha: input opacity.
 *	@param samplingRatio: the ratio between current sampling rate and the original.

 */
float opacityCorrection(in float alpha, in float sampleRatio)
{
    float a_corrected = 1.0 - pow(1.0 - alpha, sampleRatio);
    return a_corrected;
}

/**
 * Accumulation composition
 *
 * @param sample: current sample value.
 * @param samplingRatio: the ratio between current sampling rate and the original. (ray step)
 * @param composedColor: blended color (both input and output)
 */
void accumulation(float value, float sampleRatio, inout vec4 composedColor)
{
    vec4 color = transferFunction(value);
    color.a = opacityCorrection(color.a, sampleRatio);

    // TODO: Add (or implement) Front-to-back compositing
    composedColor = vec4(0.5) * value + composedColor * 0.0001F; // placeholder
}

/**
 * Main Function: Computes the color for the given fragment.
 *
 * @param fragColor OUT: The color of the pixel / fragment.
 * @param fragCoord The coordinate of the fragment in screen space
 */
void mainImage(out vec4 fragColor)
{
    // show the lookup table
    /*
    fragColor = texture(lookupTable, uv);
    return;
    */
    
    float aspect = iResolution.x / iResolution.y;

    /******************** compute camera parameters ********************/

    // camera movement
    float camSpeed = 0.5;
    vec3 camPos = 1.5 * vec3(cos(iTime*camSpeed), 0.5, sin(iTime*camSpeed));
    vec3 camDir = -normalize(camPos);
    vec3 camUp = vec3(0.0, 1.0, 0.0);
    vec3 camRight = normalize(cross(camDir, camUp));
    camUp = normalize(cross(camRight, camDir));

    /************ compute ray direction (OpenGL style) *****************/
    float fovx = 2.0 * atan(tan(fovy / 2.0) * aspect);

    vec3 uL = (tan(fovx*0.5)*zNear) * (-camRight) + (tan(fovy*0.5) * zNear) * camUp + camDir * zNear + camPos;
    vec3 lL = (tan(fovx*0.5)*zNear) * (-camRight) + (tan(fovy*0.5) * zNear) * (-camUp) + camDir * zNear + camPos;
    vec3 uR = (tan(fovx*0.5)*zNear) * camRight + (tan(fovy*0.5) * zNear) * camUp + camDir * zNear + camPos;
    vec3 lR = (tan(fovx*0.5)*zNear) * camRight + (tan(fovy*0.5) * zNear) * (-camUp) + camDir * zNear + camPos;

    vec3 targetL = mix(lL, uL, uv.y);
    vec3 targetR = mix(lR, uR, uv.y);
    vec3 target = mix(targetL, targetR, uv.x);

    vec3 rayDir = normalize(target - camPos);

    /******************* test against bounding box ********************/
    float tNear, tFar;
    bool hit = intersectBoundingBox(camPos, rayDir, tNear, tFar);
    vec4 background = vec4(0.0, 0.0, 0.0, 1.0);
    
    if (!hit)
    {
       fragColor = background;
        return;
    }

    float tstep = (bbMax.x - bbMin.x) / float(sampleNum);
    vec4 finalColor = vec4(0.0);
    vec3 finalGradient = vec3(0.0);
    // ratio between current sampling rate vs. the original sampling rate
    float sampleRatio = 1.0 / (float(sampleNum) * voxelWidth);
    /******************** main raycasting loop *******************/

    // For maximum intensity composition
    float maxIntense = 0.0;

    // For average intensity composition
    float sumIntense = 0.0;
    int   hitCount = 0;

    float t = tNear;
    int i = 0;
    while(t < tFar && i < sampleNum)
    {
        vec3 pos = camPos + t * rayDir;
        // Use normalized volume coordinate
        vec3 texCoord = vec3(pos.x + 0.5, pos.y + 0.5, pos.z + 0.5);
        float value = sampleVolume(texCoord);

        // TODO: Modify to use the pre-integration table you generated in the previous sub-task.
        // Here available as the 2D texture "lookupTable".
        finalColor += texture(lookupTable, vec2(0.5F, 0.5F)) * 0.0001F; // placeholder

        accumulation(value, sampleRatio, finalColor);

        t += tstep;
    }

    fragColor.rgb = mix(background.rgb, finalColor.rgb, finalColor.a);
    fragColor.a = 1.0F;
}

void main()
{
    mainImage(color);
}
