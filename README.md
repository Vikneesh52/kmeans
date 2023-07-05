# K-Means Clustering Header File

This is a C header file, `kmeans.h`, that provides functions for performing K-means clustering. K-means clustering is an unsupervised learning algorithm used to partition a dataset into K clusters based on similarity.

## Installation
Run this command in terminal
- git clone https://github.com/Vikneesh52/kmeans.git
- cd kmeans
- copy kmeans.h C:\MinGW\include

## Usage

1. Include the `kmeans.h` header file in your C program: `#include <kmeans.h>`.

2. The following functions are available:

   - `struct KMeansResult kmeans_fit(double* X, int n_samples, int n_features, int n_clusters)`: Fits a K-means model to the given dataset `X` with `n_samples` samples, `n_features` features, and `n_clusters` desired clusters. Returns a `struct KMeansResult` containing the cluster labels, cluster centers, and inertia.

   - `int* kmeans_predict(double* X, int n_samples, int n_features, double* cluster_centers, int n_clusters)`: Predicts the cluster labels for the given dataset `X` using the trained K-means model specified by `cluster_centers` and `n_clusters`. Returns an array of cluster labels.

   - `double* kmeans_transform(double* X, int n_samples, int n_features, double* cluster_centers, int n_clusters)`: Computes the distances from the samples in `X` to the cluster centers specified by `cluster_centers` and `n_clusters`. Returns an array of distances.

   - `double kmeans_score(double* X, int n_samples, int n_features, double* cluster_centers, int n_clusters)`: Computes the sum of squared distances from the samples in `X` to their nearest cluster center specified by `cluster_centers` and `n_clusters`. Returns the inertia.

   - `void free_kmeans_result(struct KMeansResult result)`: Frees the memory allocated for a `struct KMeansResult` object.

4. Refer to the included example program `example.c` for a usage demonstration.

## License

This header file is provided under the [MIT License](LICENSE).
