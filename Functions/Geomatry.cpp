#define pii pair<int,int>
#define ff first
#define ss second
// overlap recyangle square area
pii OverLappingArea(){
    pii bl1, tr1;// rect1
    pii bl2, tr2;// rect2
    //coordinates of first rectangle
    int w = min(tr1.ff, tr2.ff) - max(bl1.ff, bl2.ff);
    int h = min(tr1.ss, tr2.ss) - max(bl1.ss, bl2.ss);
    return {w, h};
}

// two points distance
int dist(pii &a, pii &b){
    return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}