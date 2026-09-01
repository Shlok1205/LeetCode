import java.util.*;
class Solution {
    static class State {
        int r,c,energy,mask;
        State(int r,int c,int energy,int mask) {
            this.r=r;
            this.c=c;
            this.energy=energy;
            this.mask=mask;
        }
    }
    public int minMoves(String[] classroom, int energy) {
        int m=classroom.length;
        int n=classroom[0].length();
        int[][] litter=new int[m][n];
        for(int i=0;i<m;i++)
            Arrays.fill(litter[i],-1);
        int sr=0,sc=0;
        int total=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                char ch=classroom[i].charAt(j);
                if(ch=='S') {
                    sr=i;
                    sc=j;
                }
                else if(ch=='L') {
                    litter[i][j]=total++;
                }
            }
        }
        if(total==0)
            return 0;
        int target=(1<<total)-1;
        int[][][] best=new int[m][n][1<<total];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                Arrays.fill(best[i][j],-1);
            }
        }
        Queue<State> q=new ArrayDeque<>();
        q.offer(new State(sr,sc,energy,0));
        best[sr][sc][0]=energy;
        int[][] dir={
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        int moves=0;
        while(!q.isEmpty()) {
            int size=q.size();
            while(size-->0) {
                State cur=q.poll();
                int r=cur.r;
                int c=cur.c;
                int e=cur.energy;
                int mask=cur.mask;
                if(mask==target)
                    return moves;
                if(e==0)
                    continue;
                for(int[] d:dir) {
                    int nr=r+d[0];
                    int nc=c+d[1];
                    if(nr<0 || nr>=m || nc<0 || nc>=n)
                        continue;
                    if(classroom[nr].charAt(nc)=='X')
                        continue;
                    int ne=e-1;
                    int nmask=mask;
                    if(litter[nr][nc]!=-1)
                        nmask|=(1<<litter[nr][nc]);
                    if(classroom[nr].charAt(nc)=='R')
                        ne=energy;
                    if(best[nr][nc][nmask]>=ne)
                        continue;
                    best[nr][nc][nmask]=ne;
                    q.offer(new State(nr,nc,ne,nmask));
                }
            }
            moves++;
        }
        return -1;
    }
}