#include <SDL.h>
#include <glew.h>
#include <iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include"Viewer.h"


using namespace std;

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
unsigned int center = SDL_WINDOWPOS_CENTERED;
// declaration vertex Shader
ifstream vertShader_01;
// declaration Fragment Shader
ifstream fragShader_01;
//ofstream fragShader_02("fragm")
string line;
string fileContent = "";
// convert string in to char*

string LoadShader(string filename) {
    ifstream myFile;
    myFile.open(filename);
    if (myFile.fail()) {
        cerr << "Error - failed to open" << filename << endl;
    }
    string fileText = "";
    string line = "";
    while (getline(myFile, line)) {
        fileText += line + '\n';
    }
    myFile.close();
    return fileText;
}
unsigned int CreateVertexShader(const char* shadersource) {
    unsigned int shader;
    shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader, 1, &shadersource, NULL);
    glCompileShader(shader);
    return shader;
}
unsigned int CreateFragmentShader(const char* shadersource) {
    unsigned int shader;
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &shadersource, NULL);
    glCompileShader(shader);
    return shader;
}

// char** unt tableau de tableau de char = string* un tableau de string mais un string est un tableau de char
int main(int argc = 0, char** argv = nullptr) {
    bool isViewerInit = Viewer::Instance().Initialize();
    if (isViewerInit) {
        Viewer::Instance().Load();
        Viewer::Instance().Loop();
        Viewer::Instance().Unload();
    }
    Viewer::Instance().Close();
    return 0;
}
