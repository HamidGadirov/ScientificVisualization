import numpy as np
from matplotlib import pyplot as plt
import pickle

def preprocess(data, visualize):
    # reshape, visualize, normalize, scale

    if (visualize == True):
        # visualize all data
        fig=plt.figure()
        columns = 15
        rows = 6
        for i in range(1, columns*rows+1 ):
            if (i == data.shape[0]):
                break
            img = data[i,:,:,0]
            fig.add_subplot(rows, columns, i)
            plt.imshow(img, cmap='viridis')
            
        fig = plt.gcf()
        plt.suptitle('Original data') 
        plt.show()

    # input("waiting...")
    
    # normalize data: subtract mean and std dev
    normalized_data = data

    print(normalized_data.max())
    print(normalized_data.min())

    # normalize to zero mean and unit variance
    data_mean = normalized_data.mean()
    data_std = normalized_data.std()
    normalized_data = (normalized_data - normalized_data.mean()) / normalized_data.std()
    #print("normalized:", normalized_data)
    print(normalized_data.max())
    print(normalized_data.min())
    print(normalized_data.mean())
    print(normalized_data.std())

    if (visualize == True):
        # visualize all normalized and scaled data
        fig=plt.figure()
        columns = 15
        rows = 6
        for i in range(1, columns*rows+1):
            if (i == normalized_data.shape[0]):
                break
            img = normalized_data[i,:,:,0]
            fig.add_subplot(rows, columns, i)
            plt.imshow(img, cmap='viridis', vmin=normalized_data.min(), vmax=normalized_data.max())
        
        fig = plt.gcf()
        plt.suptitle('Normalized data') 
        plt.show()

    # crop the input to remove cylinder feature;
    cropping = True
    if (cropping):
        cut_value = int(0.3*normalized_data.shape[1])
        normalized_cropped_data = normalized_data[:,cut_value:,:,:]
        print("normalized_cropped_data: ", normalized_cropped_data.shape)
    
    return normalized_cropped_data, data_mean, data_std


