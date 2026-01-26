#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 40;  // Total 40 cities
string cities[N] = {
    // Punjab Province (0-14)
    "Lahore", "Faisalabad", "Rawalpindi", "Multan", "Gujranwala",
    "Sialkot", "Bahawalpur", "Sargodha", "Sheikhupura", "Jhang",
    "Rahim Yar Khan", "Kasur", "Okara", "Mianwali", "Hafizabad",
    
    // Sindh Province (15-22)
    "Karachi", "Hyderabad", "Sukkur", "Larkana", "Nawabshah",
    "Mirpur Khas", "Thatta", "Jacobabad",
    
    // KPK Province (23-30)
    "Peshawar", "Mardan", "Abbottabad", "Mingora", "Nowshera",
    "Charsadda", "Mansehra", "Swabi",
    
    // Balochistan Province (31-36)
    "Quetta", "Gwadar", "Khuzdar", "Turbat", "Sibi", "Zhob",
    
    // Federal & Others (37-39)
    "Islamabad", "Muzaffarabad", "Gilgit"
};

// City coordinates for A* heuristic
double cityLat[N] = {
    // Punjab
    31.5497, 31.4504, 33.5651, 30.1575, 32.1877,
    32.4937, 29.3956, 32.0836, 31.7131, 31.2681,
    28.4202, 31.1156, 30.8100, 32.5853, 32.0709,
    
    // Sindh
    24.8607, 25.3960, 27.7131, 27.5584, 26.2442,
    25.5276, 24.7466, 28.2769,
    
    // KPK
    34.0150, 34.2017, 34.1463, 34.7656, 34.0158,
    34.1453, 34.3332, 34.1167,
    
    // Balochistan
    30.1798, 25.1264, 27.8000, 26.0031, 29.5430, 31.3417,
    
    // Federal & Others
    33.6844, 34.3700, 35.9208 
};

double cityLon[N] = {
    // Punjab
    74.3436, 73.1350, 73.0169, 71.5249, 74.1945,
    74.5314, 71.6722, 72.6711, 73.9783, 72.3181,
    70.2952, 74.4467, 73.4597, 71.5436, 73.6880,
    
    // Sindh
    67.0011, 68.3578, 68.8482, 68.2121, 68.4100,
    69.0126, 67.9243, 68.4514,
    
    // KPK
    71.5249, 72.0406, 73.2117, 72.7639, 71.9747,
    71.7307, 73.1990, 72.4667,
    
    // Balochistan
    66.9750, 62.3225, 66.6167, 63.0504, 67.8773, 69.4486,
    
    // Federal & Others
    73.0479, 73.4711, 74.3144
};

const int MAX_EDGES = 200;  // Increased for more connections
const int INF = 99999;

struct Edge {
    int to;        // destination city index
    int weight;    // distance / cost
    int next;      // index of next edge
};

Edge edges[MAX_EDGES];
int head[N];
int edgeCount = 0;


// ========== FUNCTION DECLARATIONS ==========
void printSeparator(char ch = '=', int width = 60);
void printHeader(string text);
void printSubHeader(string text);
void showCities();
void initGraph();
void addEdge(int u, int v, int w);
void buildGraph();
void BFS(int start, int goal);
void DFS(int start, int goal);
void UCS(int start, int goal);
void Dijkstra(int start, int goal);
void AStar(int start, int goal);
double calculateHeuristic(int city, int goal);
// ============================================

void showCities() {
    cout << "\n  Available Cities (Total: " << N << "):\n";
    cout << "  " << string(60, '-') << "\n";
    
    cout << "  Punjab (0-14):\n";
    for (int i = 0; i < 15; i++) {
        cout << "  " << i << ". " << cities[i] << "\n";
    }
    
    cout << "\n  Sindh (15-22):\n";
    for (int i = 15; i < 23; i++) {
        cout << "  " << i << ". " << cities[i] << "\n";
    }
    
    cout << "\n  KPK (23-30):\n";
    for (int i = 23; i < 31; i++) {
        cout << "  " << i << ". " << cities[i] << "\n";
    }
    
    cout << "\n  Balochistan (31-36):\n";
    for (int i = 31; i < 37; i++) {
        cout << "  " << i << ". " << cities[i] << "\n";
    }
    
    cout << "\n  Federal/Others (37-38):\n";
    for (int i = 37; i < N; i++) {
        cout << "  " << i << ". " << cities[i] << "\n";
    }
    
    cout << "  " << string(60, '-') << "\n";
}

void printSeparator(char ch, int width) {
    for (int i = 0; i < width; i++) {
        cout << ch;
    }
    cout << endl;
}

void printHeader(string text) {
    cout << "\n";
    printSeparator('=', 70);
    cout << "  " << text << endl;
    printSeparator('=', 70);
}

void printSubHeader(string text) {
    cout << "\n  +- " << text << " -+\n" << endl;
}

void initGraph() {
    for (int i = 0; i < N; i++) {
        head[i] = -1;
    }
    edgeCount = 0;
}

void addEdge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;

    edges[edgeCount].to = u;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[v];
    head[v] = edgeCount++;
}

void buildGraph() {
    initGraph();

    // Punjab Region Connections
    addEdge(0, 1, 130);    // Lahore - Faisalabad
    addEdge(0, 2, 380);    // Lahore - Rawalpindi
    addEdge(0, 3, 350);    // Lahore - Multan
    addEdge(0, 4, 70);     // Lahore - Gujranwala
    addEdge(0, 5, 125);    // Lahore - Sialkot
    addEdge(0, 6, 420);    // Lahore - Bahawalpur
    addEdge(0, 7, 190);    // Lahore - Sargodha
    addEdge(0, 8, 40);     // Lahore - Sheikhupura
    addEdge(0, 11, 55);    // Lahore - Kasur
    addEdge(0, 12, 110);   // Lahore - Okara
    
    addEdge(1, 3, 200);    // Faisalabad - Multan
    addEdge(1, 4, 60);     // Faisalabad - Gujranwala
    addEdge(1, 7, 90);     // Faisalabad - Sargodha
    addEdge(1, 9, 50);     // Faisalabad - Jhang
    
    addEdge(2, 37, 20);    // Rawalpindi - Islamabad
    addEdge(2, 23, 180);   // Rawalpindi - Peshawar
    addEdge(2, 25, 75);    // Rawalpindi - Abbottabad
    addEdge(2, 7, 210);    // Rawalpindi - Sargodha
    
    addEdge(3, 6, 90);     // Multan - Bahawalpur
    addEdge(3, 10, 120);   // Multan - Rahim Yar Khan
    addEdge(3, 9, 85);     // Multan - Jhang
    
    addEdge(4, 5, 50);     // Gujranwala - Sialkot
    addEdge(4, 7, 140);    // Gujranwala - Sargodha
    
    addEdge(6, 10, 150);   // Bahawalpur - Rahim Yar Khan
    
    addEdge(7, 13, 110);   // Sargodha - Mianwali
    addEdge(7, 14, 75);    // Sargodha - Hafizabad

    // Sindh Region Connections
    addEdge(15, 16, 160);  // Karachi - Hyderabad
    addEdge(15, 17, 500);  // Karachi - Sukkur
    addEdge(15, 18, 430);  // Karachi - Larkana
    addEdge(15, 19, 280);  // Karachi - Nawabshah
    addEdge(15, 20, 220);  // Karachi - Mirpur Khas
    addEdge(15, 21, 100);  // Karachi - Thatta
    
    addEdge(16, 17, 340);  // Hyderabad - Sukkur
    addEdge(16, 19, 150);  // Hyderabad - Nawabshah
    addEdge(16, 20, 180);  // Hyderabad - Mirpur Khas
    
    addEdge(17, 18, 110);  // Sukkur - Larkana
    addEdge(17, 22, 480);  // Sukkur - Jacobabad
    addEdge(17, 3, 450);   // Sukkur - Multan
    
    addEdge(18, 22, 130);  // Larkana - Jacobabad

    // KPK Region Connections
    addEdge(23, 24, 50);   // Peshawar - Mardan
    addEdge(23, 25, 120);  // Peshawar - Abbottabad
    addEdge(23, 26, 160);  // Peshawar - Swat
    addEdge(23, 27, 35);   // Peshawar - Nowshera
    addEdge(23, 28, 30);   // Peshawar - Charsadda
    addEdge(23, 29, 140);  // Peshawar - Mansehra
    addEdge(23, 30, 80);   // Peshawar - Swabi
    
    addEdge(24, 27, 45);   // Mardan - Nowshera
    addEdge(24, 30, 60);   // Mardan - Swabi
    
    addEdge(25, 29, 40);   // Abbottabad - Mansehra
    addEdge(25, 37, 130);  // Abbottabad - Islamabad
    
    addEdge(26, 29, 110);  // Swat - Mansehra

    // Balochistan Region Connections
    addEdge(31, 32, 700);  // Quetta - Gwadar
    addEdge(31, 33, 250);  // Quetta - Khuzdar
    addEdge(31, 34, 650);  // Quetta - Turbat
    addEdge(31, 35, 160);  // Quetta - Sibi
    addEdge(31, 36, 280);  // Quetta - Zhob
    addEdge(31, 15, 700);  // Quetta - Karachi
    
    addEdge(32, 34, 180);  // Gwadar - Turbat
    addEdge(32, 33, 520);  // Gwadar - Khuzdar
    
    addEdge(33, 35, 320);  // Khuzdar - Sibi
    addEdge(33, 15, 440);  // Khuzdar - Karachi
    
    addEdge(35, 36, 340);  // Sibi - Zhob

    // Cross-Province Connections
    addEdge(37, 38, 140);  // Islamabad - Muzaffarabad
    addEdge(37, 39, 350);  // Islamabad - Gilgit
    
    addEdge(36, 23, 240);  // Zhob - Peshawar
    addEdge(10, 15, 800);  // Rahim Yar Khan - Karachi
    addEdge(13, 23, 280);  // Mianwali - Peshawar
}

int queueArr[100];
int front = 0;
int rear = 0;

void enqueue(int x) {
    queueArr[rear++] = x;
}

int dequeue() {
    return queueArr[front++];
}

bool isEmpty() {
    return front == rear;
}

void BFS(int start, int goal) {
    bool visited[N] = {false};
    int parent[N];
    
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }
    
    front = rear = 0;
    
    enqueue(start);
    visited[start] = true;
    
    while (!isEmpty()) {
        int current = dequeue();
        
        if (current == goal) {
            break;
        }
        
        for (int i = head[current]; i != -1; i = edges[i].next) {
            int nextCity = edges[i].to;
            
            if (!visited[nextCity]) {
                visited[nextCity] = true;
                parent[nextCity] = current;
                enqueue(nextCity);
            }
        }
    }
    
    cout << "\n  ==> BFS Path (Minimum Stops):\n";
    cout << "  " << string(60, '-') << "\n";
    int path[50];
    int count = 0;
    int temp = goal;
    
    while (temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }
    
    if (parent[goal] == -1 && start != goal) {
        cout << "  No path found!\n";
    } else {
        cout << "  Route: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << cities[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << "\n  Total Stops: " << (count - 1) << endl;
        cout << "  Total Cities Visited: " << count << endl;
    }
    cout << "  " << string(60, '-') << "\n";
}

bool dfsFound = false;
int dfsParent[50];

void DFSUtil(int current, int goal, bool visited[]) {
    visited[current] = true;
    
    if (current == goal) {
        dfsFound = true;
        return;
    }
    
    for (int i = head[current]; i != -1; i = edges[i].next) {
        int nextCity = edges[i].to;
        
        if (!visited[nextCity] && !dfsFound) {
            dfsParent[nextCity] = current;
            DFSUtil(nextCity, goal, visited);
        }
    }
}

void DFS(int start, int goal) {
    bool visited[N] = {false};
    dfsFound = false;
    
    for (int i = 0; i < N; i++) {
        dfsParent[i] = -1;
    }
    
    DFSUtil(start, goal, visited);
    
    cout << "\n  ==> DFS Traversal Path:\n";
    cout << "  " << string(60, '-') << "\n";
    
    if (!dfsFound && start != goal) {
        cout << "  No path found!\n";
    } else {
        int path[50];
        int count = 0;
        int temp = goal;
        
        while (temp != -1) {
            path[count++] = temp;
            temp = dfsParent[temp];
        }
        
        cout << "  Route: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << cities[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << "\n  Total Stops: " << (count - 1) << endl;
    }
    cout << "  " << string(60, '-') << "\n";
}

int findMinCostNode(int cost[], bool visited[]) {
    int minCost = INF;
    int minIndex = -1;
    
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[i] < minCost) {
            minCost = cost[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void UCS(int start, int goal) {
    int cost[N];
    bool visited[N];
    int parent[N];
    
    for (int i = 0; i < N; i++) {
        cost[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    cost[start] = 0;
    
    while (true) {
        int current = findMinCostNode(cost, visited);
        
        if (current == -1)
            break;
        
        if (current == goal)
            break;
        
        visited[current] = true;
        
        for (int i = head[current]; i != -1; i = edges[i].next) {
            int nextCity = edges[i].to;
            int weight = edges[i].weight;
            
            if (!visited[nextCity]) {
                if (cost[current] + weight < cost[nextCity]) {
                    cost[nextCity] = cost[current] + weight;
                    parent[nextCity] = current;
                }
            }
        }
    }
    
    cout << "\n  ==> UCS Path (Minimum Cost):\n";
    cout << "  " << string(60, '-') << "\n";
    int path[50];
    int count = 0;
    int temp = goal;
    
    while (temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }
    
    if (parent[goal] == -1 && start != goal) {
        cout << "  No path found!\n";
    } else {
        cout << "  Route: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << cities[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << "\n  Total Cost: " << cost[goal] << " km\n";
    }
    cout << "  " << string(60, '-') << "\n";
}

int findMinDistanceNode(int dist[], bool visited[]) {
    int minDist = INF;
    int minIndex = -1;
    
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Dijkstra(int start, int goal) {
    int dist[N];
    bool visited[N];
    int parent[N];
    
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    dist[start] = 0;
    
    for (int count = 0; count < N - 1; count++) {
        int current = findMinDistanceNode(dist, visited);
        
        if (current == -1)
            break;
        
        visited[current] = true;
        
        for (int i = head[current]; i != -1; i = edges[i].next) {
            int nextCity = edges[i].to;
            int weight = edges[i].weight;
            
            if (!visited[nextCity] && dist[current] + weight < dist[nextCity]) {
                dist[nextCity] = dist[current] + weight;
                parent[nextCity] = current;
            }
        }
    }
    
    cout << "\n  ==> Dijkstra Shortest Path:\n";
    cout << "  " << string(60, '-') << "\n";
    int path[50];
    int countPath = 0;
    int temp = goal;
    
    while (temp != -1) {
        path[countPath++] = temp;
        temp = parent[temp];
    }
    
    if (parent[goal] == -1 && start != goal) {
        cout << "  No path found!\n";
    } else {
        cout << "  Route: ";
        for (int i = countPath - 1; i >= 0; i--) {
            cout << cities[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << "\n  Total Distance: " << dist[goal] << " km\n";
    }
    cout << "  " << string(60, '-') << "\n";
}

double calculateHeuristic(int city, int goal) {
    // Haversine formula for distance between two coordinates
    double lat1 = cityLat[city] * M_PI / 180.0;
    double lon1 = cityLon[city] * M_PI / 180.0;
    double lat2 = cityLat[goal] * M_PI / 180.0;
    double lon2 = cityLon[goal] * M_PI / 180.0;
    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    
    double a = sin(dlat/2) * sin(dlat/2) + 
               cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    // Earth's radius in km
    return 6371.0 * c;
}

int findMinFNode(int gCost[], bool visited[], int goal) {
    int minF = INF;
    int minIndex = -1;
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            double h = calculateHeuristic(i, goal);
            int f = gCost[i] + (int)h;
            if (f < minF) {
                minF = f;
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void AStar(int start, int goal) {
    int gCost[N];
    bool visited[N];
    int parent[N];
    
    for (int i = 0; i < N; i++) {
        gCost[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    gCost[start] = 0;
    
    while (true) {
        int current = findMinFNode(gCost, visited, goal);
        
        if (current == -1)
            break;
        
        if (current == goal)
            break;
        
        visited[current] = true;
        
        for (int i = head[current]; i != -1; i = edges[i].next) {
            int nextCity = edges[i].to;
            int weight = edges[i].weight;
            
            if (!visited[nextCity]) {
                if (gCost[current] + weight < gCost[nextCity]) {
                    gCost[nextCity] = gCost[current] + weight;
                    parent[nextCity] = current;
                }
            }
        }
    }
    
    cout << "\n  ==> A* Path (Smart & Fast):\n";
    cout << "  " << string(60, '-') << "\n";
    int path[50];
    int count = 0;
    int temp = goal;
    
    while (temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }
    
    if (parent[goal] == -1 && start != goal) {
        cout << "  No path found!\n";
    } else {
        cout << "  Route: ";
        for (int i = count - 1; i >= 0; i--) {
            cout << cities[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << "\n  Total Distance: " << gCost[goal] << " km\n";
        cout << "  Heuristic: Straight-line distance based on coordinates\n";
    }
    cout << "  " << string(60, '-') << "\n";
}

int main() {
    buildGraph();
    
    bool continueLoop = true;
    int searchCount = 0;
    
    while (continueLoop) {
        if (searchCount == 0) {
            printHeader("INTELLIGENT ROUTE ENGINE - 38 PAKISTANI CITIES");
        } else {
            printHeader("FIND ANOTHER ROUTE");
        }
        showCities();
        
        int source, destination;
        cout << "\n   Enter source city index (0-" << N-1 << "): ";
        cin >> source;
        
        cout << "   Enter destination city index (0-" << N-1 << "): ";
        cin >> destination;
        
        // Validate input
        if (source < 0 || source >= N || destination < 0 || destination >= N) {
            cout << "\n";
            printSeparator('-', 70);
            cout << "  Invalid city index! Please enter values between 0-" << N-1 << ".\n";
            printSeparator('-', 70);
            cout << "\n";
            continue;
        }
        
        if (source == destination) {
            cout << "\n";
            printSeparator('-', 70);
            cout << "  Source and destination are the same!\n";
            cout << "  Path: " << cities[source] << endl;
            printSeparator('-', 70);
            cout << "\n";
            
            char another;
            cout << "  Want to find another route? (Y/N): ";
            cin >> another;
            if (another != 'Y' && another != 'y') {
                continueLoop = false;
            }
            cout << "\n";
            searchCount++;
            continue;
        }
        
        printSubHeader("ROUTE PREFERENCE OPTIONS");
        cout << "  1. Minimum number of stops (BFS)\n";
        cout << "  2. Traversal path (DFS)\n";
        cout << "  3. Cheapest route (UCS)\n";
        cout << "  4. Shortest distance (Dijkstra)\n";
        cout << "  5. Smart & fast route (A* Search)\n";
        cout << "\n  Enter your choice (1-5): ";
        int choice;
        cin >> choice;
        
        cout << "\n";
        printSeparator('-', 70);
        
        switch (choice) {
            case 1:
                cout << "  ==> You selected: Minimum Stops Route (BFS)\n";
                printSeparator('-', 70);
                BFS(source, destination);
                break;
                
            case 2:
                cout << "  ==> You selected: Traversal Path (DFS)\n";
                printSeparator('-', 70);
                DFS(source, destination);
                break;
                
            case 3:
                cout << "  ==> You selected: Cheapest Route (UCS)\n";
                printSeparator('-', 70);
                UCS(source, destination);
                break;
                
            case 4:
                cout << "  ==> You selected: Shortest Distance Route (Dijkstra)\n";
                printSeparator('-', 70);
                Dijkstra(source, destination);
                break;
                
            case 5:
                cout << "  ==> You selected: Smart & Fast Route (A* Search)\n";
                printSeparator('-', 70);
                AStar(source, destination);
                break;
                
            default:
                cout << "  Invalid choice! Please enter 1-5.\n";
                printSeparator('-', 70);
                cout << "\n";
                continue;
        }
        
        printSeparator('-', 70);
        
        char another;
        cout << "\n  Want to find another route? (Y/N): ";
        cin >> another;
        
        if (another != 'Y' && another != 'y') {
            continueLoop = false;
        }
        cout << "\n";
        searchCount++;
    }
    
    printHeader("THANK YOU FOR USING THE SYSTEM");
    cout << "  +-- Total routes searched: " << searchCount << "  --+" << endl;
    cout << "  Goodbye! Safe travels!\n";
    printSeparator('=', 70);
    cout << "\n";
    
    return 0;
}