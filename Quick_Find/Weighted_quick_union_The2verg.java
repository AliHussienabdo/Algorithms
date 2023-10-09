package Quick_Find;
// the main difference between weighted quick union and 
// quick union is that weight quick union is more faster because 
// it's keeping track of the size of each component (tree) in it
// and it make the small tree point to the long tree
// so it would be faster 
public class Weighted_quick_union_The2verg {
	
	private int[] id;
	private int[] sz; // to track the height tree 
	private int count; // count the number of components
	
	public Weighted_quick_union_The2verg(int size){
		id = new int[size];
		sz = new int[size];
		count = size;
		
		for(int i=0;i<size;++i) id[i] = i;
		for(int i=0;i<size;++i) sz[i] = 1;
		
	}
	
	public boolean connected(int p,int q) {
		return find(p) == find(q);
	}
	
	public int Count() {
		return count;
	}
	
	public int find(int p) {
		while(p != id[p]) p = id[p];
		return p;
	}
	
	public void union(int p,int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		
		if(pRoot == qRoot) return;
		
		if(sz[pRoot] > sz[qRoot]) {
		    id[qRoot] = pRoot;
		    sz[pRoot] += sz[qRoot];
		}
		else {
			id[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
		}
		count--;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Weighted_quick_union_The2verg UF = new Weighted_quick_union_The2verg(5);
		UF.union(1, 2); // 0 1 1 3 4
		UF.union(4, 3); // 0 1 1 3 3 
		UF.union(1, 4);// 0 1 1 1 1
		System.out.println( UF.connected(1, 4));

	}
	
	
	
	

}
