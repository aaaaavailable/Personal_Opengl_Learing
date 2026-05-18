//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//using std::cout;
//using std::endl;
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
////指定三角形三个顶点的坐标
//float vertices[] = {
//    0.5f, 0.5f, 0.0f,   // 右上角
//    0.5f, -0.5f, 0.0f,  // 右下角
//    -0.5f, -0.5f, 0.0f, // 左下角
//    -0.5f, 0.5f, 0.0f   // 左上角
//};
//unsigned int indices[] = {  // 注意索引从0开始! 
//    0, 1, 3,   // 第一个三角形
//    1, 2, 3    // 第二个三角形
//};
//
////硬编码一个用着色器语言（GLSL）编写的顶点着色器源代码
//const char* vertexShaderSource = "#version 330 core\n"
//"layout(location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{gl_Position = vec4(aPos.x , aPos.y ,aPos.z , 1.0f);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f , 0.5f , 0.2f ,1.0f);\n"
//"}\0";
//
//int main() {
//    //初始化窗口
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "opengl Learing", NULL ,NULL);
//    if (window == NULL) {
//        cout << "failed to create a window" << endl;
//        glfwTerminate();
//        return -1;
//        }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        cout << "failed to initialize GLAD" << endl;
//        return -1;
//    }
//
//    //生成并绑定一个带有GL_A***_B***编号的顶点缓存对象
//    unsigned int VBO;
//    glGenBuffers(1, &VBO);
//    unsigned int VAO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //创建着色器并用上述代码编译它
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//	unsigned int EBO;   
//	glGenBuffers(1, &EBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // check for shader compile errors
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    //顶点着色器已经编译完毕，下面开始片段着色器
//
//    //步骤和顶点着色器差不多
//    unsigned int fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    //接下来要把两个着色器对象连接到着色器程序
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();//创建程序
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram); //将着色器绑定到程序上
//
//    glUseProgram(shaderProgram);//调用程序
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);//删除调用
//    
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//告诉opengl如何解析顶点数据
//    glEnableVertexAttribArray(0);//以顶点属性位置为参数，启用顶点属性
//    
//    //render loop
//    while (!glfwWindowShouldClose(window)) {
//        processInput(window);
//
//        glClearColor(0.2f, 0.3f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glBindVertexArray(0);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//        
//    }
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//    glfwTerminate();
//    return 0;
//}
//
//void processInput(GLFWwindow* window) {
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}