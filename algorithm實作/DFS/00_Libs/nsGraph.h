#ifndef NSGRAPH_H_INCLUDED
#define NSGRAPH_H_INCLUDED

#include "./nsDLL.h"

class GNode {
private:
	int id;
	double weight;
	int color;
	string label;
public:
	GNode(int num=-1) {
		setAll(num, 1, 0, "*");
	}
	GNode(int pId, double pWeight, int pColor=0, string pLabel="*") {//這裡和insertEdge中的e_vu有關  w的1去掉
		setAll(pId, pWeight, pColor, pLabel);
	}
	int getId() {
		return id;
	}
	void setId(int num) {
		id = num;
	}
	int getColor() {
		return color;
	}
	void setColor(int pColor) {
		color = pColor;
	}
	string getLabel() {
		return label;
	}
	void setLabel(string pLabel) {
		label = pLabel;
	}
	double getWeight() {
		return weight;
	}
	void setWeight(double pWeight) {
		weight = pWeight;
	}
	void setAll(int pId=-1, double pWeight=1, int pColor=0, string pLabel="") {
		id = pId;
		weight = pWeight;
		color = pColor;
		label = pLabel;
	}
	bool operator==(const GNode& nd) {
		return id==nd.id;
	}
	bool operator<(const GNode& nd) {
		return id<nd.id;
	}
	bool operator!=(const GNode& nd) {
		return id!=nd.id;
	}
	bool operator<=(const GNode& nd) {
		return id<=nd.id;
	}
	bool operator>(const GNode& nd) {
		return id>nd.id;
	}
	bool operator>=(const GNode& nd) {
		return id>=nd.id;
	}
	void show(bool showColor=false, bool showWeight=false, bool showLabel=false) {
		string colorText[] = {"White", "Gray", "Black"};
		cout << "(" << id;
		if (showLabel) cout << "-" << label;
		if (showColor) {
			cout << ", " << colorText[color] << " ";
		}
		if (showWeight){
			cout << ", " << weight;
		}
		cout << ")";
	}
	friend ostream& operator<<(ostream& os, const GNode& nd) {
		os << "(" << nd.id;
		os << "-" << nd.label;
		os << ", " << nd.color;
		os << ", " << nd.weight;
		os << ")";
		return os;
	}
};

typedef DLL<GNode> AdjList ;
class MyGraph {
private:
	GNode* V;
	DLL<GNode>* E;
	bool isDirected;
	int n, m; // |V|:n, |E|:m

	string genEdgeLabel(int u, int v) {
		string edgeLabel = "E";
		edgeLabel += (char)(u+'0');
		edgeLabel += "-";
		edgeLabel += (char)(v+'0');
		return edgeLabel;
	}
	GNode guard;
public:
	MyGraph(int pN, bool pDirected=false) {
		isDirected = pDirected;
		n=pN;
		m = 0;
		V = new GNode[n];
		E = new DLL<GNode>[n];
		for ( int i=0; i<n; ++i ) {
			V[i].setAll( i, 0, 0, string(1,(char)(i+'0')) );
		}
		guard = GNode();
	}
MyGraph(const char* csFile) {
	ifstream gDef;
	gDef.open(csFile);
	if ( !gDef ) {
		cerr << "Can't open file!" << endl;
		exit(1);
	}

	guard = GNode();
	int directed;
	gDef >> n >> directed;
	isDirected = (directed==1);
	m = 0;
	V = new GNode[n];
	E = new DLL<GNode>[n];

	for ( int i=0; i<n; ++i ) {
		V[i].setAll( i, 0, 0, "*" );
	}
	int nodeBeg, nodeEnd;
	double weight;
	while ( !gDef.eof() ) {
		gDef >> nodeBeg >> nodeEnd >> weight;
		insertEdge( nodeBeg, nodeEnd, weight );
	}
	gDef.close();
}

~MyGraph() {
	delete [] V;
	delete [] E;
}

void insertEdge( int u, int v, double w ) {//w=0 的0去掉
	GNode e_uv(v, w, 0, genEdgeLabel(u,v));
	E[u].insEnd(e_uv);
	++m;
	if ( !isDirected ) {
		GNode e_vu(u, w, 0, genEdgeLabel(v,u));
		E[v].insEnd(e_vu);
	}
}

int sizeV() { return n; }
int sizeE() { return m; }

int outDegree(int v) {
	if ( v<0 || v>=n ) return -1;
	return E[v].size();
}

GNode& node(int v) {
	if ( v<0 || v>=n ) return guard;
	return V[v];
}

AdjList& adjList(int v) {
	return E[v];
}

vector<GNode> outNeighbor(int v) {
	if ( v<0 || v>=n ) return vector<GNode>();
	return E[v].toVector();
}
	void delNode(int u) {
	}
	void delEdge(int u, int v) {
	}
	void absorbs(int u, int v) {
	}
	void show() {
		cout << endl;
		for ( int i=0; i<n; ++i ) {
			V[i].show(true, false, true); cout << " : "; E[i].show(); cout << endl;
		}
	}
};

#endif // NSGRAPH_H_INCLUDED
