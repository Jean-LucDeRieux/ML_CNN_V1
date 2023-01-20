Convolutional Neural Network
Program Developed by Jean-Luc DeRieux
Last editied - 01/14/2023


About: Convolutional Neural Network (CNN) are used for classification Machine Learning
models.

Project Overlay:
- Convolution: Convolves matrix by another matrix. This includes pooling
- NeuralNet: Creates a Nerual Network (Multi-Level Perceptron) with fixed number of nodes. It stores
the weights so that the model can be used again.
- CNN



CNN Model Visilized:

Input * Kernal = Feature Map   -> Feature Map Flattend -> Falttend FM into Nerual Network = Classfication

I also need stochastic gradient descent (SGD) for weights and biases to update

Resources: 
https://blog.xrds.acm.org/2016/06/convolutional-neural-networks-cnns-illustrated-explanation/
"The kernels are then convolved with the input volume to obtain so-called ‘activation maps’."

https://medium.com/analytics-vidhya/how-to-choose-the-size-of-the-convolution-filter-or-kernel-size-for-cnn-86a55a1e2d15
"1x1 kernel size is only used for dimensionality reduction that aims to reduce the number of channels. It captures the interaction of input channels in just one pixel of feature map. Therefore, 1x1 was eliminated as the features extracted will be finely grained and local that too with no information from the neighboring pixels.
2x2 and 4x4 are generally not preferred because odd-sized filters symmetrically divide the previous layer pixels around the output pixel. And if this symmetry is not present, there will be distortions across the layers which happens when using an even sized kernels, that is, 2x2 and 4x4. So, this is why we don’t use 2x2 and 4x4 kernel sizes.
Therefore, 3x3 is the optimal choice to be followed by practitioners until now. But it is still the most expensive parts!"


https://machinelearningmastery.com/convolutional-layers-for-deep-learning-neural-networks/
"For example, below is a hand crafted 3×3 element filter for detecting vertical lines:
0.0, 1.0, 0.0
0.0, 1.0, 0.0
0.0, 1.0, 0.0
Applying this filter to an image will result in a feature map that only contains vertical lines. It is a vertical line detector.
You can see this from the weight values in the filter; any pixels values in the center vertical line will be positively activated and any on either side will be negatively activated. Dragging this filter systematically across pixel values in an image can only highlight vertical line pixels.
A horizontal line detector could also be created and also applied to the image, for example:
0.0, 0.0, 0.0
1.0, 1.0, 1.0
0.0, 0.0, 0.0
Combining the results from both filters, e.g. combining both feature maps, will result in all of the lines in an image being highlighted."