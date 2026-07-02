import java.util.*;

class Solution {
    static class State {
        int row, col, health;

        State(int row, int col, int health) {
            this.row = row;
            this.col = col;
            this.health = health;
        }
    }

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {

        int m = grid.size();
        int n = grid.get(0).size();

        int[][] best = new int[m][n];
        for (int[] row : best)
            Arrays.fill(row, -1);

        int startHealth = health - grid.get(0).get(0);

        if (startHealth <= 0)
            return false;

        PriorityQueue<State> pq = new PriorityQueue<>(
                (a, b) -> b.health - a.health);

        pq.offer(new State(0, 0, startHealth));
        best[0][0] = startHealth;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!pq.isEmpty()) {

            State curr = pq.poll();

            if (curr.row == m - 1 && curr.col == n - 1)
                return true;

            if (curr.health < best[curr.row][curr.col])
                continue;

            for (int i = 0; i < 4; i++) {

                int nr = curr.row + dr[i];
                int nc = curr.col + dc[i];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int newHealth = curr.health - grid.get(nr).get(nc);

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    pq.offer(new State(nr, nc, newHealth));
                }
            }
        }

        return false;
    }
}