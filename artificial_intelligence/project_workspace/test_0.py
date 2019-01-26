'''
    Script to execution of training and test of neural network, utilizing
    2 images for each category (letter) and 2 categories

    File containing the prepared dataset file is 'dataset_test_0.arff'
'''
from read_data import LoadData
from neural_network_4 import MLP
import numpy as np


# Load of data from file
loader = LoadData(number_of_images=2, number_of_pixels=784, number_of_categories=2, database_name='dataset_test_0.arff')

print('=' * 20)
for elem in loader.all_images:
    print('%s -> %s' % (elem.category, elem.filename))
print('=' * 20)

# Convert output classes from letter to number
loader.convert_categories_to_number()

# Get numpy images and your respective categories
input_images, output_classes = loader.get_numpy_images_and_categories()

training_images = np.array([input_images[0], input_images[1]])
training_outputs = np.array([output_classes[0], output_classes[1]])

test_images = np.array([input_images[2], input_images[3]])
test_outputs = np.array([output_classes[2], output_classes[3]])

# Create neural network
mlp = MLP(training_images, training_outputs, hidden_layer_0=784, output_layer=1, learning_rate=0.6, number_of_classes=10)

# Test the network before training
mlp.feed_forward(test_images[1])
result = mlp.get_rounded_result()
print('output: %s -> %s' % (mlp.output_of_output_layer, test_outputs[1]))
mlp.feed_forward(test_images[0])
result = mlp.get_rounded_result()
print('output: %s -> %s' % (mlp.output_of_output_layer, test_outputs[0]))
# print(loader.convert_categories(result), ' -> ', output_classes[0])
print('=  =  ' * 10)

mlp.learn(epochs=2000)

# Test the network after training
mlp.feed_forward(test_images[1])
result = mlp.get_rounded_result()
print('output: %s -> %s' % (mlp.output_of_output_layer, test_outputs[1]))
mlp.feed_forward(test_images[0])
result = mlp.get_rounded_result()
print('output: %s -> %s' % (mlp.output_of_output_layer, test_outputs[0]))
# print(loader.convert_categories(result))