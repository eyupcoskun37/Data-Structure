#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_K 10
#define MAX_ITER 100

// Mesafe hesabı
double distance(double *a, double *b, int dim)
{
    double sum = 0;
    for (int i = 0; i < dim; i++)
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    return sqrt(sum);
}

// Rastgele merkez seç
void init_centroids(double **data, double **centroids, int n, int k, int dim)
{
    for (int i = 0; i < k; i++)
    {
        int r = rand() % n;
        for (int d = 0; d < dim; d++)
            centroids[i][d] = data[r][d];
    }
}

// K-Means çalıştır ve inertia (toplam hata) döndür
double kmeans(double **data, int n, int dim, int k)
{
    int *labels = malloc(n * sizeof(int));
    double **centroids = malloc(k * sizeof(double *));
    for (int i = 0; i < k; i++)
        centroids[i] = malloc(dim * sizeof(double));

    init_centroids(data, centroids, n, k, dim);

    for (int iter = 0; iter < MAX_ITER; iter++)
    {

        // Noktaları en yakın merkeze ata
        for (int i = 0; i < n; i++)
        {
            double bestDist = DBL_MAX;
            int bestCluster = 0;

            for (int c = 0; c < k; c++)
            {
                double d = distance(data[i], centroids[c], dim);
                if (d < bestDist)
                {
                    bestDist = d;
                    bestCluster = c;
                }
            }
            labels[i] = bestCluster;
        }

        // Yeni merkezleri hesapla
        double **new_centroids = calloc(k, sizeof(double *));
        int *count = calloc(k, sizeof(int));
        for (int c = 0; c < k; c++)
            new_centroids[c] = calloc(dim, sizeof(double));

        for (int i = 0; i < n; i++)
        {
            int c = labels[i];
            for (int d = 0; d < dim; d++)
                new_centroids[c][d] += data[i][d];
            count[c]++;
        }

        for (int c = 0; c < k; c++)
        {
            if (count[c] > 0)
                for (int d = 0; d < dim; d++)
                    centroids[c][d] = new_centroids[c][d] / count[c];
        }

        for (int c = 0; c < k; c++)
            free(new_centroids[c]);
        free(new_centroids);
        free(count);
    }

    // Inertia (toplam hata)
    double inertia = 0;
    for (int i = 0; i < n; i++)
        inertia += distance(data[i], centroids[labels[i]], dim);

    // Bellek temizle
    for (int i = 0; i < k; i++)
        free(centroids[i]);
    free(centroids);
    free(labels);

    return inertia;
}

int main()
{
    int n = 10;  // veri sayısı
    int dim = 2; // boyut

    // -------- ÖRNEK VERİ --------
    double raw[10][2] = {
        {1, 1}, {1.2, 1.1}, {0.8, 1.1}, {5, 5}, {5.2, 5}, {4.8, 5.1}, {9, 1}, {9.2, 1.1}, {8.8, 0.9}, {9, 0.8}};

    // Pointer dizisi (C zorunluluğu)
    double **data = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        data[i] = raw[i];

    // -------- Farklı K değerlerini dene --------
    double inertia[MAX_K];

    for (int k = 1; k <= MAX_K; k++)
    {
        inertia[k] = kmeans(data, n, dim, k);
        printf("k = %d, inertia = %f\n", k, inertia[k]);
    }

    // -------- En iyi K'yi seç (Elbow mantığı: en büyük düşüş) --------
    int best_k = 2;
    double best_drop = 0;

    for (int k = 2; k <= MAX_K; k++)
    {
        double drop = inertia[k - 1] - inertia[k];
        if (drop > best_drop)
        {
            best_drop = drop;
            best_k = k;
        }
    }

    printf("\nOtomatik seçilen en uygun k = %d\n", best_k);

    return 0;
}
