# Mức độ tương quan của hai thuộc tính
import pandas as pd
import numpy as np


def sigma(df, col):
    n = len(df[col])  
    sum_x = np.sum(df[col])
    sum_x_squared = np.sum(df[col]**2)
    return np.sqrt((sum_x_squared / n) - (sum_x / n)**2)

def r(df, x_col, y_col):
    x_mean = df[x_col].mean()
    y_mean = df[y_col].mean()
    xy_mean = (df[x_col] * df[y_col]).mean()

    sigma_x = sigma(df, x_col)
    sigma_y = sigma(df, y_col)
    
    r = (xy_mean - x_mean * y_mean) / (sigma_x * sigma_y)   
    return r

df = pd.read_csv(".\LAB01\data.csv")

print(df)

r = r(df, "Luong", "Tuoi")
print("r = ", r)

# kết quả: r =  0.001324112291334066