import numpy as np


# Attempt to develop MLP :(


class MLP:

    def __init__(self, X, Y, hidden_layer_0=3, output_layer=2, learning_rate=0.5, number_of_classes=1):
        self.input                  = X
        self.output                 = Y
        self.weight_hidden_layer_0  = np.random.rand(hidden_layer_0, self.input.shape[1]) / 100000
        self.weight_output_layer    = np.random.rand(output_layer, hidden_layer_0) / 1000000
        self.learning_rate          = learning_rate
        self.number_of_classes      = number_of_classes

        self.output = self.normalize(self.output)

    def sigmoid(self, x):
        return 1 / (1.0 + np.exp(-x))

    def derivative_sigmoid(self, x):
        return x * (1 - x)

    def feed_forward(self, input):
        self.input_of_hidden_layer_0     = np.dot(self.weight_hidden_layer_0, input)
        self.output_of_hidden_layer_0    = self.sigmoid(self.input_of_hidden_layer_0)

        self.input_of_output_layer   = np.dot(self.weight_output_layer, self.output_of_hidden_layer_0)
        self.output_of_output_layer  = self.sigmoid(self.input_of_output_layer)

        if self.output_of_output_layer > 0.9999:
            self.output_of_output_layer = self.output_of_output_layer * 0.9999

    def back_propagation(self, input, output):
        self.error = output - self.output_of_output_layer

        output_layer_error      = self.error * self.derivative_sigmoid(self.output_of_output_layer)
        d_weight_output_layer   = np.dot(output_layer_error, self.output_of_hidden_layer_0.T) * self.learning_rate

        hidden_layer_error      = np.dot(self.weight_output_layer.T, output_layer_error) * self.derivative_sigmoid(self.output_of_hidden_layer_0)
        d_weight_hidden_layer_0 = np.dot(hidden_layer_error, input.T) * self.learning_rate

        self.weight_output_layer    += d_weight_output_layer
        self.weight_hidden_layer_0  += d_weight_hidden_layer_0

    def get_rounded_result(self):
        output_of_output_layer = self.denormalize(self.output_of_output_layer)
        return output_of_output_layer.round()

    def normalize(self, number):
        return number / self.number_of_classes

    def denormalize(self, number):
        return number * self.number_of_classes

    def normalize_outputs(self):
        self.output_of_output_layer = self.normalize(self.output_of_output_layer)
        self.output = self.normalize(self.output)

    def denormalize_outputs(self):
        self.output_of_output_layer = self.denormalize(self.output_of_output_layer)
        self.output = self.denormalize(self.output)

    def learn(self, epochs=7000):

        for i in range(epochs):
            for k in range(self.input.shape[0]):
                input   = self.input[k]
                output  = self.output[k]

                self.feed_forward(input)
                self.back_propagation(input, output)





# # Variables
# input = np.array([[[0], [0]],
#                   [[0], [1]],
#                   [[1], [0]],
#                   [[1], [1]]])
#
# output = np.array([[[0]],
#                    [[0.25]],
#                    [[0.5]],
#                    [[1]]])
#
# mlp = MLP(input, output, hidden_layer_0=250, output_layer=1, learning_rate=0.3)
#
# mlp.feed_forward([[1], [0]])
# print(mlp.output_of_output_layer)
#
# mlp.learn(100)
# print('= ' * 10)
# mlp.feed_forward([[0], [0]])
# print(mlp.output_of_output_layer)
# mlp.feed_forward([[0], [1]])
# print(mlp.output_of_output_layer)
# mlp.feed_forward([[1], [0]])
# print(mlp.output_of_output_layer)
# mlp.feed_forward([[1], [1]])
# print(mlp.output_of_output_layer)
