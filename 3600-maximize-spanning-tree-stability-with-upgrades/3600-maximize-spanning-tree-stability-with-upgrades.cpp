class DSU {
public:
    vector<int> p;

    DSU(int n){
        p.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
    }

    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        p[b]=a;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long maxW = 0;
        for(auto &e:edges) maxW = max(maxW, 2LL*e[2]);

        auto can = [&](long long x){

            DSU dsu(n);
            int used = 0;
            int upgrades = 0;

            // mandatory edges
            for(auto &e:edges){
                int u=e[0],v=e[1],s=e[2],must=e[3];

                if(must){
                    if(s < x) return false;
                    if(!dsu.unite(u,v)) return false;
                    used++;
                }
            }

            // optional edges that already satisfy
            for(auto &e:edges){
                if(e[3]) continue;

                int u=e[0],v=e[1],s=e[2];

                if(s>=x && dsu.unite(u,v)){
                    used++;
                    if(used==n-1) return true;
                }
            }

            // optional edges that need upgrade
            for(auto &e:edges){
                if(e[3]) continue;

                int u=e[0],v=e[1],s=e[2];

                if(s<x && 2LL*s>=x && upgrades<k && dsu.unite(u,v)){
                    upgrades++;
                    used++;
                    if(used==n-1) return true;
                }
            }

            return used==n-1;
        };

        long long l=0,r=maxW,ans=-1;

        while(l<=r){
            long long mid = l+(r-l)/2;

            if(can(mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return (int)ans;
    }
};