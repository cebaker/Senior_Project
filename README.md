# Speech Processing for Machine Learning



## Contributors

Academic Advisor: Li Tan

Cedrick Baker

Mingjun Yang

Zhanxuan Mei




## Abstract

The goal of this project was to develop a voice recognition system using neural networks. This system has been implemented with two major software steps and a hardware implementation. Subsequent steps rely on the precision of the former steps to achieve higher accuracy for the overall system.
Feature extraction is the first and therefore one of the most important steps in this system. Linear Predictive coding (LPC) methods where considered for feature extraction but yielded only 10 features from the voice signal while Mel-Frequency Cestrum Coefficients (MFCC) extracts 26 features allowing a higher resolution picture of the waveform. Many forms of neural networks where tried and tested for the word prediction system. These networks included K Nearest Neighbor (KNN), Artificial Neural Networks (ANN), Convolutional Neural Networks (CNN) and the team-named MFCC Image which is a method in which MFCC is used to extract features and build an image to train and drive a CNN.
All the methods above where implemented and refined using MATLAB™. Later a hardware implementation using a much smaller ANN was built on an Arduino 101™ using weights that where trained using MATLAB™. This smaller neural network is only 2 layers due to the lack of memory in the Arduino 101™ and only uses 10 of the 26 features available from the MFCC extraction process. Due to all these limitations in the hardware the neural network can be trained on four words and has an accuracy of around 75 percent depending on the word.

## Example
[Project Working Example](https://youtu.be/AcSA56dY44E)


