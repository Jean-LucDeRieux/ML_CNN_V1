Project: C++ Convolutional Neural Network
Developer: Jean-Luc DeRieux
Editied: 01/23/2023


About: Convolutional Neural Network (CNN) are used for classification. As an examle this could be used to classify images of Dogs or Cats.


Objects:
    Matrix: Creates matrix object which can be used to store pixel intensity values [0-255]
    Perceptron: Creates an instance of a Perceptron which then can be connected to other Perceptrons.
    NerualNet: Creates a nerual network with Perceptron objects.

Namespaces:
    matrix_tools: A namespace that includes Matrix object manipulation such as convolution and pooling along with some helper functions that make these operations possible.


CNN Model Steps Visilized:

1.) Convolution stage(Can be multiple layers): 
    --------------    -----------------     --------------
    |             |   |               |    |             |
    | Input Image | * | Kernal Matrix |  = | Feature Map |
    |             |   |               |    |             |
    ---------------   -----------------     --------------
2.) Downpooling stage (Meant to reduce rows/columns of matrix) Can use Max or Average pooling
    --------------      -------------       --------------------------
    |             |     |           |      |                         |
    | Feature Map | --> |  Pooling  |  --> | Down-scaled Feature Map |
    |             |     |           |      |                         |
    ---------------     -------------       --------------------------
3.) Flattning
    ---------------------------      [Pixel 1]
    |                         |      [Pixel 2]
    | Down-scaled Feature Map | -->  ...
    |                         |      [Pixel n-1]
    ---------------------------      [Pixel n]
4.) Nerual Network
    [Pixel 1]         ---------------
    [Pixel 2]         |             |
    ...           --> | Nerual Net  |   = Classfication 
    [Pixel n-1]       |             |
    [Pixel n]         ---------------


Note: Stochastic gradient descent (SGD) is used for weights and biases to update ML model for accuracy/


To build the program on a Windows system, the following steps should be taken:
    1.) Open the Command Prompt by tapping the Windows button and typing "CMD" and tapping enter.
    2.) Change the directory of the Command Prompt to the desired location for the cloned machine learning model.
    3.) Type "git clone https://github.com/Jean-LucDeRieux/ML_CNN_V1.git" to clone the program from Github.
    4.) Type "cd ML_CNN_V1" to navigate into the cloned directory.
    5.) Type "mkdir build && cd build && cmake .." to create a build directory, navigate into it, and build the program using the CMakeLists.txt file.
    6.) Type "cmake --build ." to compile the current build setup.
    7.) Change the directory to the newly created debug folder by typing "cd Debug".
    8.) Type ".\matrixTesting.exe" or another .exe file to run the program.

Resources:
    https://blog.xrds.acm.org/2016/06/convolutional-neural-networks-cnns-illustrated-explanation/
    https://medium.com/analytics-vidhya/how-to-choose-the-size-of-the-convolution-filter-or-kernel-size-for-cnn-86a55a1e2d15
    https://machinelearningmastery.com/convolutional-layers-for-deep-learning-neural-networks/
    https://google.github.io/styleguide/cppguide.html

Please note that this is a general description of the program, and it may not be complete or fully functional. If you have any questions or require additional information, please reach out to the developer, Jean-Luc DeRieux.