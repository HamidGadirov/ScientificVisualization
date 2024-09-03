#version 330 core
// isolines geometry shader

layout (lines_adjacency) in;
layout (line_strip, max_vertices = 4) out;

uniform bool useInterpolation;
uniform bool ambiguousCaseMidpoint;
uniform float rho;

in VS_OUT
{
    float value;
    int greaterThanRho;
} gs_in[];

void main()
{
    if (useInterpolation || ambiguousCaseMidpoint) // Nonsense computation to avoid unused uniform variables.
    {
        float tmp = rho * 1.0E-10F; // Nonsense computation to avoid unused uniform variables.

        // Placeholder code to demonstrate how to retrieve the positions and emit vertices.
        gl_Position = tmp + gl_in[0].gl_Position; EmitVertex();
        gl_Position = tmp + gl_in[1].gl_Position; EmitVertex();
        gl_Position = tmp + gl_in[2].gl_Position; EmitVertex();
        gl_Position = tmp + gl_in[3].gl_Position; EmitVertex();
        EndPrimitive();
    }
}
