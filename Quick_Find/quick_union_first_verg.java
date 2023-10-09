package Quick_Find;
// it's quick union first version
// quick union more efficient than quick find 
// because it's not going throw the whole array to update
// the values of the of the component it's just update the root
public class quick_union_first_verg {
	
	private int[] id ;
	private int count = 0;
	
	public quick_union_first_verg(int sz){
		id = new int[sz];
		for(int i=0;i<sz;++i) {
			id[i] = i;
			System.out.print(id[i] + " ");
		}
		System.out.println();
		count = sz;
	}
	
	public int Count() {
		return count;
	}
	
	public boolean connected(int p,int q) {
		return find(p) == find(q);
	}
	
	public int find(int p) {
		while(p != id[p]) p = id[p];
		return p;
	}
	
	public void union(int p,int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		
		if(pRoot == qRoot) return;
		
		id[pRoot] = qRoot;
		count--;
		
	}
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		quick_union_first_verg UF = new quick_union_first_verg(10);
		UF.union(9, 1); 
		UF.union(3, 4);  
		UF.union(5, 8);
		UF.union(7, 2); 
		UF.union(2, 1); 
		UF.union(5, 7);
		UF.union(0, 3);
		UF.union(4, 2);
		System.out.println( UF.connected(1, 4));

	}

}
