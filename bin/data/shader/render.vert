#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
in vec2 texcoord;
in vec4 color;

uniform sampler2DRect posTex;
uniform vec2 screen;

out vec4 vColor;

void main() {

    vec2 pixPos = texture(posTex, texcoord).xy;

    pixPos.x = pixPos.x * screen.x - screen.x/2;
    pixPos.y = pixPos.y * screen.x - screen.x/2;

    vColor = color;

    gl_Position = modelViewProjectionMatrix * vec4(pixPos, 0.0, 1.0);

}
