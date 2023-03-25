class point{
    int i,j,k;
    point(int i, int j, int k) {
        this.i = i ;
        this.j = j;
        this.k = k;

    }

    public static void main(String[] args) {
        point ptarr[];
        ptarr = new point[4];

        ptarr[0] = new point(0,0,0);
        ptarr[1] = new point(1,0,0);
        ptarr[2] = new point(0,1,0);
        ptarr[3] = new point(0,0,1);

        System.out.println(ptarr.length);
    }
}