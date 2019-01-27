'''
    Script to execution of training and test of neural network, utilizing
    100 images for each category (letter) and 3 categories and 100 training epochs

    Training utilizing holdout method

    File containing the prepared dataset file is 'test_0/dataset_test_0.arff'
'''
from bot_data_preparer import data_preparation
from read_data import *
from neural_network import MLP
import numpy as np
import matplotlib.pyplot as plt


# Prepare data in file
# data_preparation(number_of_images=100,
#                  number_of_pixels=784,
#                  number_of_categories=3,
#                  database_name='notMNIST_small',
#                  dataset_source='http://yaroslavvb.blogspot.com/2011/09/notmnist-dataset.html',
#                  store_into_file='test_0/dataset_test_0.arff')

# Load of data from file
loader = LoadData(number_of_images=100,
                  number_of_pixels=784,
                  number_of_categories=3,
                  dataset_file='test_0/dataset_test_0.arff')

print('=' * 20)
for elem in loader.all_images:
    print('%s -> %s' % (elem.category, elem.filename))
print('=' * 20)

# Convert output classes from letter to number
loader.convert_categories_to_number()

# Get numpy images and your respective categories
input_images, output_classes = loader.get_numpy_images_and_categories()

training_images, test_images = get_training_test_set(input_images, percentual_for_test=0.6)
training_outputs, test_outputs = get_training_test_set(output_classes, percentual_for_test=0.6)

# Create neural network
mlp = MLP(training_images, training_outputs, hidden_layer_0=784, output_layer=1, learning_rate=0.9, normalization_factor=10)

# Test the network before training
print('total accuracy = %f%%' % (get_accuracy(test_images, test_outputs, mlp)*100))
print('=  =  ' * 10)

epochs, accuracies = mlp.learn(epochs=100, test_images=test_images, test_outputs=test_outputs)

# Test the network after training
print('total accuracy = %f%%' % (get_accuracy(test_images, test_outputs, mlp)*100))
print('=  =  ' * 10)

# print(error)

# result_file_log = open('test_0_error_rate', 'w')
# result_file_log.write(str(error))
# for e in error:
#     result_file_log.write('%s -> %s' % (e[0], e[1]))
# result_file_log.close()

plt.suptitle('Teste 0.2')
plt.title('Utilizando 100 imagens para cada categoria (letra) e 3 categorias\n treinamento durante 100 épocas e taxa de aprendizado = 0.9', fontsize=8)
plt.xlabel('Época')
plt.ylabel('Acurácia %')
plt.ylim(0, 100)
plt.plot(epochs, accuracies)
plt.show()