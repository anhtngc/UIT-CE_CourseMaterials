import numpy as np
import pandas as pd
from itertools import combinations

def create_binary_matrix(df):
    return pd.crosstab(df['MaHoaDon'], df['MatHang'])

def generate_candidates(prev_candidates, k):
    return set([tuple(sorted(set(i) | set(j))) 
                for i in prev_candidates 
                for j in prev_candidates 
                if len(set(i) | set(j)) == k])
def count_support(itemset, transactions):
    return sum(1 for transaction in transactions if set(itemset).issubset(transaction))

def apriori(df, min_support):
    transactions = [set(transaction) for transaction in df.groupby('MaHoaDon')['MatHang'].apply(list)]
    items = set(df['MatHang'])
    itemsets = [{(item,) for item in items}]
    k = 1
    
    while True: 
        if not itemsets[k-1]: 
            break
        
        candidates = generate_candidates(itemsets[k-1], k+1)
        frequent_itemsets = set()
        
        for candidate in candidates:
            frequent_itemsets.add(candidate)
        
        if frequent_itemsets:
            itemsets.append(frequent_itemsets)
        k += 1
        
        if k > len(itemsets):
            break

    frequent_itemsets =  itemsets 
    SP = []
    n = len(df['MaHoaDon'].unique())

    for k, itemset in enumerate(frequent_itemsets, 1):
        for items in itemset:
            support_value = count_support(items, [set(transaction) for transaction in df.groupby('MaHoaDon')['MatHang'].apply(list)])
            normalized_value = support_value / n  
            if normalized_value >= min_support:  
                SP.append((items, normalized_value)) 
                print(f"  {items}: {normalized_value:.2f}")

    return SP

def find_maximal_itemsets(itemsets):
    maximal_itemsets = []
    sorted_itemsets = sorted(itemsets, key=lambda x: len(x[0]), reverse=True)
    
    for itemset, support in sorted_itemsets:
        if not any(set(itemset).issubset(set(larger_itemset)) 
                   for larger_itemset, _ in maximal_itemsets):
            maximal_itemsets.append((itemset, support))
    
    return maximal_itemsets

def generate_rules(itemset):
    rules = []
    for i in range(1, len(itemset)):
        for antecedent in combinations(itemset, i):
            consequent = tuple(item for item in itemset if item not in antecedent)
            rules.append((antecedent, consequent))
    return rules

def calculate_confidence(rule, transactions):
    antecedent, consequent = rule
    antecedent_support = count_support(antecedent, transactions)
    rule_support = count_support(antecedent + consequent, transactions)
    return rule_support / antecedent_support if antecedent_support > 0 else 0

def find_association_rules(df, min_support, min_confidence):
    transactions = [set(transaction) for transaction in df.groupby('MaHoaDon')['MatHang'].apply(list)]
    frequent_itemsets = apriori(df, min_support)
    maximal_itemsets = find_maximal_itemsets(frequent_itemsets)
    
    all_rules = []
    for itemset, support in maximal_itemsets:
        rules = generate_rules(itemset)
        for rule in rules:
            confidence = calculate_confidence(rule, transactions)
            if confidence >= min_confidence:
                all_rules.append((rule, support, confidence))
    
    return all_rules

df = pd.read_csv("HoaDon_MatHang.csv")

min_support = 0.4
SP = apriori(df, min_support)

print(f"Bài 1: Các tập phổ biến không thỏa ngưỡng {min_support} là: ", )
for item, support in SP:
    print(item, end=', ')
print("\n")
print(f"Bài 2: Các tập phổ biến cực đại là: ", )
maximal_itemsets = find_maximal_itemsets(SP)
for itemset, support in maximal_itemsets:
    print(f"{itemset}: {support:.2f}")

min_confidence = 0.8
rules = find_association_rules(df, min_support, min_confidence)
print("\n")
print(f"Bài 3: Các luật kết hợp thỏa mãn min_support={min_support} và min_confidence={min_confidence}:")
for rule, support, confidence in rules:
    antecedent, consequent = rule
    print(f"{antecedent} -> {consequent}: support={support:.2f}, confidence={confidence:.2f}")