import numpy as np
from read_data import get_accuracy


# Attempt to develop MLP :(


class MLP:

    def __init__(self, X, Y, hidden_layer_0=3, output_layer=2, learning_rate=0.5, normalization_factor=1):
        self.input                  = X
        self.output                 = Y
        self.weight_hidden_layer_0  = np.random.rand(hidden_layer_0, self.input.shape[1]) / 100000
        self.weight_output_layer    = np.random.rand(output_layer, hidden_layer_0) / 1000000
        self.learning_rate          = learning_rate
        self.number_of_classes      = normalization_factor

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
        elif self.output_of_output_layer < 0.0001:
            self.output_of_output_layer = self.output_of_output_layer + 0.0001

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
        # return self.output_of_output_layer.round()

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


    def learn(self, epochs=1000, test_images=None, test_outputs=None):
        epoc    = []
        accur   = []

        if test_images is None:
            for i in range(epochs):
                print('epoch = %d' % i)
                for k in range(self.input.shape[0]):
                    self.feed_forward(self.input[k])
                    self.back_propagation(self.input[k], self.output[k])

        else:
            for i in range(epochs):
                # print('epoch = %d' % i)
                for k in range(self.input.shape[0]):
                    self.feed_forward(self.input[k])
                    self.back_propagation(self.input[k], self.output[k])

                accuracy = get_accuracy(test_images, test_outputs, self)*100

                print('epoch %s -> accuracy = %f%%' % (i, accuracy))
                epoc.append(i)
                accur.append(accuracy)

        return epoc, accur

    def learn_with_cross_validation(self, epochs=100, fold_number=10):
        epoch   = []
        accur   = []

        amount      = int(self.input.shape[0] / fold_number)
        input_fold  = [self.input[j:j+amount] for j in range(0, self.input.shape[0], amount)]
        output_fold = [self.output[j:j+amount] for j in range(0, self.input.shape[0], amount)]

        # Separate the test fold and training folds
        epo = 0
        for i in range(fold_number):
            test_input_fold     = input_fold[i]
            test_output_fold    = output_fold[i]

            training_input_fold     = []
            training_output_fold    = []
            for t in range(len(input_fold)):
                if t == i:  # The training fold can not be the same for the test fold
                    continue
                for j in range(len(input_fold[t])):
                    training_input_fold.append(input_fold[t][j])
                    training_output_fold.append(output_fold[t][j])

            for e in range(epochs):
                for k in range(len(training_input_fold)):
                    input   = training_input_fold[k]
                    output  = training_output_fold[k]

                    self.feed_forward(input)
                    self.back_propagation(input=input, output=output)

                epo += 1
                accuracy = get_accuracy(test_input_fold, self.denormalize(test_output_fold), self) * 100
                epoch.append(epo)
                accur.append(accuracy)
                print('fold #%s epoch #%s -> accuracy = %f%%' % (i, e, accuracy))

            accuracy = get_accuracy(test_input_fold, self.denormalize(test_output_fold), self) * 100

            print('fold #%s -> accuracy = %f%%' % (i, accuracy))

        return epoch, accur




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
