package Quick_Find;
// quick find algorithm to solve the problem of 
// dynamic connectivity
public class QF {
	private int[] id;
	private int count = 0;
	
	public QF(int sz) {
		count = sz;
		id = new int[sz];
		for(int i=0;i<sz;++i) {
			id[i] = i;
			System.out.print(id[i] + " ");
		}
		System.out.println("\n");
	}
	
	public int Count() {
		return count;
	}
	
	public int find(int p) {
		if(p >= 0 && p < id.length) {
			return id[p];
		}
		return -1;
	}
	
	public boolean connected(int p,int q) {
		return find(p) == find(q);
	}
	
	public void union(int p,int q) {
		int ip = find(p);
		int iq = find(q);
		//before modification
		System.out.println(p + " " + q);
		
		if(ip == iq) return;
		int NumOfAccessing = 0;
		
		for(int i=0;i<id.length;++i) {
			if(id[i] == ip) {
				id[i] = iq;
				++NumOfAccessing;
			}
			
		}
		//after modification
		for(int i=0;i<id.length;++i)System.out.print(id[i] + " ");
		System.out.println("\nThe Number of Accessing the array : " + NumOfAccessing);
		
		
		count--;
	}
	
	public static void main(String[] args) {
		// 9-0 3-4 5-8 7-2 2-1 5-7 0-3 4-2
		QF qf = new QF(10);
		qf.union(9, 1); // 0 1 1 3 4
		qf.union(3, 4); // 0 1 1 3 3 
		qf.union(5, 8);// 0 1 1 1 1
		qf.union(7, 2); // 0 1 1 3 4
		qf.union(2, 1); // 0 1 1 3 3 
		qf.union(5, 7);// 0 1 1 1 1
		qf.union(0, 3);
		qf.union(4, 2);
		System.out.println( qf.connected(1, 4));
		
	}
	
	

}
