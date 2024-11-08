# Cài đặt cây quyết định dùng cách tính hệ số Gini

import pandas as pd
import numpy as np

def gini_index(column):
    # Calculate Gini Index for a column 
    counts = column.value_counts()
    probabilities = counts / len(column)
    gini = 1 - np.sum(probabilities ** 2)
    return gini

def gini_gain(data, attribute, target="Play?"):
    # Calculate Gini Gain for an attribute
    # Gini Gain = Gini(parent) - Σ((n_child/n_parent) * Gini(child))
    total_gini = gini_index(data[target])
    
    # Calculate weighted gini for each value of the attribute
    values = data[attribute].unique()
    weighted_gini = 0
    for value in values:
        subset = data[data[attribute] == value]
        weighted_gini += (len(subset) / len(data)) * gini_index(subset[target])
    
    gain = total_gini - weighted_gini
    return gain

def build_tree(data, features, target="Play?"):
    # Build decision tree using Gini Index
    # Base cases
    if len(data[target].unique()) == 1:
        return data[target].iloc[0]
    if not features:
        return data[target].mode()[0]
    
    # Calculate Gini gain for all features
    gains = {feature: gini_gain(data, feature, target) for feature in features}
    
    # Print Gini gains for visualization
    print("Gini Gains: ", end="")
    for feature, gain in gains.items():
        print(f'{feature}: {round(gain,4)}', end=" ")
    print("")
    
    # Select feature with maximum gain
    best_feature = max(gains, key=gains.get)
    print(f"Best feature: {best_feature} (gain = {round(gains[best_feature],4)})", end="\n")
    
    # Create tree structure and build recursively
    tree = {best_feature: {}}
    remaining_features = [feat for feat in features if feat != best_feature]
    
    for value in data[best_feature].unique():
        subset = data[data[best_feature] == value]
        subtree = build_tree(subset, remaining_features, target)
        tree[best_feature][value] = subtree

    return tree

def print_tree(tree, indent=""):
    # Print decision tree in a readable format
    if isinstance(tree, dict):
        for key, value in tree.items():
            print(f"{indent}{key}")
            for sub_key, sub_tree in value.items():
                print(f"{indent}  └── {sub_key}: ", end="")
                print_tree(sub_tree, indent + "    ")
    else:
        print(tree)

data = pd.read_csv("data.csv")

# List of features (excluding target and identifier columns)
features = data.columns.drop(['Play?', 'Day']).tolist()

# Build decision tree using Gini Index
decision_tree = build_tree(data, features)

# Display the tree
print("\nDecision Tree (built by using Gini Index):")
print_tree(decision_tree)