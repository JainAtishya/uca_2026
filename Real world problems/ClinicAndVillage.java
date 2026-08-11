
import java.util.PriorityQueue;
import java.util.Scanner;

class ClinicAndVillage {

    static class Village {

        int clinics;
        int population;
        double load;

        public Village(int clinics, int population, double load) {
            this.clinics = clinics;
            this.population = population;
            this.load = load;
        }

    }

    public static double minMaxLoad(int[] villages, int n, int k) {
        PriorityQueue<Village> pq = new PriorityQueue<>((a, b) -> Double.compare(b.load, a.load));

        for (int population : villages) {
            pq.offer(new Village(1, population, population));
        }

        k -= n;

        while (k-- > 0) {
            Village currentVillage = pq.poll();
            int currClinics = currentVillage.clinics;
            int population = currentVillage.population;
            double newLoad = (double) population / (currClinics + 1);
            pq.offer(new Village(currClinics + 1, population, newLoad));
        }

        return pq.peek().load;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] population = new int[n];

        for (int i = 0; i < n; i++) {
            population[i] = sc.nextInt();
        }

        int k = sc.nextInt();
        double answer = minMaxLoad(population, n, k);

        System.out.printf("%.2f", answer);
        sc.close();

    }

}

// You are given n villages and must open k clinics across them. The population of each village is provided, and initially, no village has a clinic.
// Distribute the k clinics among the villages while satisfying the following conditions:
// Every village must have at least one clinic.
// Residents can only visit clinics within their own village (no travel between villages is allowed).
// Clinics in the same village share the village's population equally.
// Allocate the clinics such that the maximum patient load on any single clinic is minimized.
// Given that k ≥ n, return the minimum possible maximum load on any clinic.
// Example
// Input
// n = 3
// population = [200, 20, 50]
// k = 5
// Output
// 66.67
// Explanation
// Allocate the clinics as [3, 1, 1], meaning:
// Village 1: 3 clinics → load = 200 / 3 = 66.67
// Village 2: 1 clinic → load = 20 / 1 = 20
// Village 3: 1 clinic → load = 50 / 1 = 50
// The maximum load across all clinics is 66.67, which is the minimum achievable.
