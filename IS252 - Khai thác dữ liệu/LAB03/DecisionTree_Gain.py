# Cài đặt cây quyết định dùng cách tính Information Gain

import pandas as pd
import numpy as np

# Load the dataset from CSV file
data = pd.read_csv("data.csv")

# Function to calculate entropy
def entropy(column):
    counts = column.value_counts()
    probabilities = counts / len(column)
    ent = -np.sum(probabilities * np.log2(probabilities))
    return ent

# Function to calculate information gain
def information_gain(data, attribute, target="Play?"):
    total_entropy = entropy(data[target])
    values = data[attribute].unique()
    weighted_entropy = 0
    for value in values:
        subset = data[data[attribute] == value]
        weighted_entropy += (len(subset) / len(data)) * entropy(subset[target])
    gain = total_entropy - weighted_entropy
    return gain

# Recursive function to build the decision tree
def build_tree(data, features, target="Play?"):
    if len(data[target].unique()) == 1:
        return data[target].iloc[0]  # Return the class label if only one class is left
    if not features:
        return data[target].mode()[0]  # Return the most common class if no features are left
    
    gains = {feature: information_gain(data, feature, target) for feature in features}
    print("Infomation_Gain: ", end="")
    for feature, gain in gains.items():
        print(f'{feature}: {round(gain,4)}', end=" ")
    print("")
    best_feature = max(gains, key=gains.get)
    print("max_gain: ", best_feature, end="\n")
    
    tree = {best_feature: {}}
    remaining_features = [feat for feat in features if feat != best_feature]
    
    for value in data[best_feature].unique():
        subset = data[data[best_feature] == value]
        subtree = build_tree(subset, remaining_features, target)
        tree[best_feature][value] = subtree

    return tree

# Print the decision tree with indentation
def print_tree(tree, indent=""):
    if isinstance(tree, dict):
        for key, value in tree.items():
            print(f"{indent}{key}")
            for sub_key, sub_tree in value.items():
                print(f"{indent}  └── {sub_key}: ", end="")
                print_tree(sub_tree, indent + "    ")
    else:
        print(tree)

# List of features (excluding the target and identifier column)
features = data.columns.drop(['Play?', 'Day']).tolist()

# Build the decision tree
decision_tree = build_tree(data, features)

# Display the decision tree structure
print("\nDecision Tree (built by using Information Gain):")
print_tree(decision_tree)
