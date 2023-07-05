#include <stdio.h>
#include <kmeans.h>

int main() {
    // Sample data
    double X[] = {1.0, 1.0, 2.0, 2.0, 5.0, 4.0, 5.0, 5.0, 9.0, 8.0, 9.0, 10.0};
    int n_samples = 6;
    int n_features = 2;
    int n_clusters = 2;

    // Fit K-means model
    struct KMeansResult result = kmeans_fit(X, n_samples, n_features, n_clusters);

    // Print cluster labels
    printf("Cluster labels:\n");
    for (int i = 0; i < n_samples; i++) {
        printf("%d ", result.labels[i]);
    }
    printf("\n");

    // Print cluster centers
    printf("Cluster centers:\n");
    for (int i = 0; i < n_clusters; i++) {
        for (int j = 0; j < n_features; j++) {
            printf("%.2f ", result.cluster_centers[i * n_features + j]);
        }
        printf("\n");
    }

    // Compute distances to cluster centers
    double* distances = kmeans_transform(X, n_samples, n_features, result.cluster_centers, n_clusters);

    // Print distances
    printf("Distances to cluster centers:\n");
    for (int i = 0; i < n_samples; i++) {
        for (int j = 0; j < n_clusters; j++) {
            printf("%.2f ", distances[i * n_clusters + j]);
        }
        printf("\n");
    }

    // Compute inertia (sum of squared distances)
    double inertia = kmeans_score(X, n_samples, n_features, result.cluster_centers, n_clusters);
    printf("Inertia: %.2f\n", inertia);

    // Free allocated memory
    free_kmeans_result(result);
    free(distances);

    return 0;
}
