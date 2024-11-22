import pandas as pd
import numpy as np
import random
import matplotlib.pyplot as plt

# Hàm tính khoảng cách Euclidean giữa các điểm và centroid
def calculate_distance(point, centroid):
    return np.sqrt(np.sum((point - centroid) ** 2))

# Thuật toán K-Means
def kmeans(X, k, centroids):
    prev_centroids = centroids.copy()
    iteration = 0  
    
    while True:
        iteration += 1
        print(f"\n=== Gom cụm lần {iteration} ===")

        clusters = [[] for _ in range(k)]
        for point in X:
            distances = [calculate_distance(point, centroid) for centroid in centroids]
            closest_centroid = np.argmin(distances)
            clusters[closest_centroid].append(point)
        for i, cluster in enumerate(clusters):
            print(f"Cụm {i + 1}: {cluster}")
        
        new_centroids = []
        for i in range(k):
            if len(clusters[i]) > 0:
                new_centroid = np.mean(clusters[i], axis=0)
            else:
                new_centroid = centroids[i]
            new_centroids.append(new_centroid)
            print(f"Centroid mới của cụm {i + 1}: {new_centroid}")
        
        if np.allclose(new_centroids, prev_centroids):
            print("\nCentroid không thay đổi, thuật toán dừng lại.")
            break
        else:
            print("\nCentroid thay đổi, tiếp tục lặp...")
        
        prev_centroids = new_centroids.copy()
        centroids = np.array(new_centroids)
    
    return clusters, centroids
    
def plot_clusters_with_labels(X, clusters, centroids):
    colors = ['r', 'g', 'b', 'c'] 
    plt.figure(figsize=(8, 6))
    
    for i, cluster in enumerate(clusters):
        cluster = np.array(cluster)
        if len(cluster) > 0:
            plt.scatter(cluster[:, 0], cluster[:, 1], c=colors[i], label=f'Cụm {i + 1}')
            for j, point in enumerate(cluster):
                plt.text(point[0], point[1] - 0.05, f"x{np.where((X == point).all(axis=1))[0][0] + 1}", 
                         fontsize=9, color=colors[i], ha='center')

            plt.scatter(
                centroids[i][0], centroids[i][1], 
                c=colors[i], marker='o', edgecolor='black', s=200, label=f'Centroid {i + 1}'
            )
            plt.text(centroids[i][0], centroids[i][1] - 0.05, f"Centroid{i + 1}", 
                     fontsize=10, color='black', ha='center')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Biểu đồ phân cụm K-Means')
    plt.legend()
    plt.grid()
    plt.savefig("kmeans_clusters.png")
    print("Biểu đồ được lưu trong file 'kmeans_clusters.png'")
    
df = pd.read_csv("data.csv")

print("Dữ liệu ban đầu:")
print(df)

k = 3

X = df[['x', 'y']].values

# Chọn ngẫu nhiên k điểm từ dữ liệu làm các centroid ban đầu
centroids = X[random.sample(range(len(X)), k)]
print("\nCentroid ban đầu:")
for i, centroid in enumerate(centroids):
    print(f"Centroid {i + 1}: {centroid}")

clusters, final_centroids = kmeans(X, k, centroids)

print("\nKết quả phân cụm cuối cùng:")
for i, cluster in enumerate(clusters):
    print(f"Cụm {i + 1}: {cluster}")
    
print("\nCác centroid cuối cùng:")
print(final_centroids)

# Vẽ đồ thị
plot_clusters_with_labels(X, clusters, final_centroids)
