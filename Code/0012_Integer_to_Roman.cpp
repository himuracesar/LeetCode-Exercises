"use strict";

var vs = `#version 300 es

in vec4 a_position;
in vec4 a_color;

uniform mat4 u_matrix;

out vec4 v_color;

void main() {
  // Multiply the position by the matrix.
  gl_Position = u_matrix * a_position;

  // Pass the color to the fragment shader.
  v_color = a_color;
}
`;

var fs = `#version 300 es
precision highp float;

// Passed in from the vertex shader.
in vec4 v_color;

uniform vec4 u_colorMult;

out vec4 outColor;

void main() {
   outColor = v_color * u_colorMult;
}
`;

function main() {
  // Get A WebGL context
  /** @type {HTMLCanvasElement} */
  var canvas = document.querySelector("#canvas");
  var gl = canvas.getContext("webgl2");
  if (!gl) {
    return;
  }

  // Tell the twgl to match position with a_position, n
  // normal with a_normal etc..
  twgl.setAttributePrefix("a_");

  var sphereBufferInfo = flattenedPrimitives.createSphereBufferInfo(gl, 10, 12, 6);
  var cubeBufferInfo   = flattenedPrimitives.createCubeBufferInfo(gl, 20);
  var coneBufferInfo   = flattenedPrimitives.createTruncatedConeBufferInfo(gl, 10, 0, 20, 12, 1, true, false);

  // setup GLSL program
  var programInfo = twgl.createProgramInfo(gl, [vs, fs]);

  var sphereVAO = twgl.createVAOFromBufferInfo(gl, programInfo, sphereBufferInfo);
  var cubeVAO   = twgl.createVAOFromBufferInfo(gl, programInfo, cubeBufferInfo);
  var coneVAO   = twgl.createVAOFromBufferInfo(gl, programInfo, coneBufferInfo);

  function degToRad(d) {
    return d * Math.PI / 180;
  }

  var fieldOfViewRadians = degToRad(60);

  // Uniforms for each object.
  var sphereUniforms = {
    u_colorMult: [0.5, 1, 0.5, 1],
    u_matrix: m4.identity(),class Solution {
public:
    string intToRoman(int num) {
        int base[4] = { 1000, 100, 10, 1};
        
        string romanNum = "";
        
        int n = 0;
        for(auto i = 0; i < 4; i++)
        {
            n = num / base[i];
            
            if(n == 0)
                continue;
            
            if(n > 5 && n < 9)
            {
                romanNum += GetRomanNum(5, base[i]);
                romanNum += GetRomanNum(n - 5, base[i]);
            }
            else
            {
                romanNum += GetRomanNum(n, base[i]);
            }
            
            num = num - n * base[i];
        }
        
        return romanNum;
        
    }
    
    string GetRomanNum(int n, int base)
    {
        string romanNum = "";
        
        switch(n)
        {
            case 1:
            case 2:
            case 3: 
                for(auto index = 0; index < n; index++)
                {
                    if(base == 1000)
                        romanNum += "M";
                    else if(base == 100)
                        romanNum += "C";
                    else if(base == 10)
                        romanNum += "X";
                    else if(base == 1)
                        romanNum += "I";
                }
                
                break;
                
            case 4:
                if(base == 100)
                    romanNum += "CD";
                else if(base == 10)
                    romanNum += "XL";
                else if(base == 1)
                    romanNum += "IV";
                
                break;
                
            case 5:
                if(base == 100)
                    romanNum += "D";
                else if(base == 10)
                    romanNum += "L";
                else if(base == 1)
                    romanNum += "V";
                
                break;
                
            case 9:
                if(base == 100)
                    romanNum += "CM";
                else if(base == 10)
                    romanNum += "XC";
                else if(base == 1)
                    romanNum += "IX";
                
                break;
        }
        
        return romanNum;
    }
    
    
};
  };
  var cubeUniforms = {
    u_colorMult: [1, 0.5, 0.5, 1],
    u_matrix: m4.identity(),
  };
  var coneUniforms = {
    u_colorMult: [0.5, 0.5, 1, 1],
    u_matrix: m4.identity(),
  };
  var sphereTranslation = [  0, 0, 0];
  var cubeTranslation   = [-40, 0, 0];
  var coneTranslation   = [ 40, 0, 0];

  function computeMatrix(viewProjectionMatrix, translation, xRotation, yRotation) {
    var matrix = m4.translate(viewProjectionMatrix,
        translation[0],
        translation[1],
        translation[2]);
    matrix = m4.xRotate(matrix, xRotation);
    return m4.yRotate(matrix, yRotation);
  }

  requestAnimationFrame(drawScene);

  // Draw the scene.
  function drawScene(time) {
    time = time * 0.0005;

    twgl.resizeCanvasToDisplaySize(gl.canvas);

    // Tell WebGL how to convert from clip space to pixels
    gl.viewport(0, 0, gl.canvas.width, gl.canvas.height);

    gl.enable(gl.CULL_FACE);
    gl.enable(gl.DEPTH_TEST);

    // Compute the projection matrix
    var aspect = gl.canvas.clientWidth / gl.canvas.clientHeight;
    var projectionMatrix =
        m4.perspective(fieldOfViewRadians, aspect, 1, 2000);

    // Compute the camera's matrix using look at.
    var cameraPosition = [0, 0, 100];
    var target = [0, 0, 0];
    var up = [0, 1, 0];
    var cameraMatrix = m4.lookAt(cameraPosition, target, up);

    // Make a view matrix from the camera matrix.
    var viewMatrix = m4.inverse(cameraMatrix);

    var viewProjectionMatrix = m4.multiply(projectionMatrix, viewMatrix);

    var sphereXRotation =  time;
    var sphereYRotation =  time;
    var cubeXRotation   = -time;
    var cubeYRotation   =  time;
    var coneXRotation   =  time;
    var coneYRotation   = -time;

    gl.useProgram(programInfo.program);

    // ------ Draw the sphere --------

    // Setup all the needed attributes.
    gl.bindVertexArray(sphereVAO);

    sphereUniforms.u_matrix = computeMatrix(
        viewProjectionMatrix,
        sphereTranslation,
        sphereXRotation,
        sphereYRotation);

    // Set the uniforms we just computed
    twgl.setUniforms(programInfo, sphereUniforms);

    twgl.drawBufferInfo(gl, sphereBufferInfo);

    // ------ Draw the cube --------

    // Setup all the needed attributes.
    gl.bindVertexArray(cubeVAO);

    cubeUniforms.u_matrix = computeMatrix(
        viewProjectionMatrix,
        cubeTranslation,
        cubeXRotation,
        cubeYRotation);

    // Set the uniforms we just computed
    twgl.setUniforms(programInfo, cubeUniforms);

    twgl.drawBufferInfo(gl, cubeBufferInfo);

    // ------ Draw the cone --------

    // Setup all the needed attributes.
    gl.bindVertexArray(coneVAO);

    coneUniforms.u_matrix = computeMatrix(
        viewProjectionMatrix,
        coneTranslation,
        coneXRotation,
        coneYRotation);

    // Set the uniforms we just computed
    twgl.setUniforms(programInfo, coneUniforms);

    twgl.drawBufferInfo(gl, coneBufferInfo);

    requestAnimationFrame(drawScene);
  }
}

main();
