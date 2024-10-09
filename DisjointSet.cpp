class DisjointSet{
private:
    vector<int>parent,rank,size; //things required for DisjointSet
public:
    DisjointSet(int n){
        parent.resize(n+1); 
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;//mark all parent because at start everyone is parent of itself
            size[i] = 1; //mark all size to 1 because at start all the components have size 1 which is individual nodes
        }
    }
    //recursive function to find the ultimate parent of a node
    int find_ul_parent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find_ul_parent(parent[node]);
    }   
    void unionByRank(int u,int v){
        //firts find ultimate parent of given nodes u and v
        int ul_parent_u = find_ul_parent(u);
        int ul_parent_v = find_ul_parent(v);
        //check which has lesser rank then attach the lesser rank wala to the greater rank
        if(rank[ul_parent_u] < rank[ul_parent_v]){
            parent[ul_parent_u] = ul_parent_v;//update the parent of lesser rank
        }
        else if(rank[ul_parent_u] > rank[ul_parent_v]){
            parent[ul_parent_v] = ul_parent_u;//update the parent of lesser rank
        }
        else{
            //if rank is equal then attach anyone to anyone
            parent[ul_parent_v] = ul_parent_u;//attaching v to u
            rank[ul_parent_u]++;//increase the rank of u because v is attaching to u
        }
    }
    void unionBySize(int u,int v){
        //first find the ultimate parent of both the given nodes u and v 
        int ul_parent_u = find_ul_parent(u);
        int ul_parent_v = find_ul_parent(v);
        //connect the node which has lesser size to the greater size wala
        if(size[ul_parent_u] < size[ul_parent_v]){
            parent[ul_parent_u] = ul_parent_v;//update the parent of lesser size
            size[ul_parent_v] += size[ul_parent_u];//so greater size wala increase its size because someone is connecting with this guy
        }
        else{
            //is size if equal connect anyone to anyone
            parent[ul_parent_v] = ul_parent_u;//connecting v to u so updating parent of v
            size[ul_parent_u] += size[ul_parent_v]; // so v connecting to u so size of u increase and add the size of v to itself
        }
    }
};
