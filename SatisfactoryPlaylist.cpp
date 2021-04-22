/*
	You have access to ranked lists of songs for various users. Each song is represented as an integer, and more preferred songs appear earlier in each list. For example, the list [4, 1, 7] indicates that a user likes song 4 the best, followed by songs 1 and 7.

	Given a set of these ranked lists, interleave them to create a playlist that satisfies everyone's priorities.

	For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}. In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
*/


// ----------------------------------------


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef vector<bool> boolArray;
typedef vector<int> playlist;
typedef vector<vector<int>> adjacencyList;


const int NUM_SONGS = 10; // for testing purpose (songs start from 0)
adjacencyList graph(NUM_SONGS);
boolArray hasParent(NUM_SONGS, false);
boolArray visited(NUM_SONGS, false);
playlist result;

void _dfs(int song) {
	if (visited[song]) return;

	visited[song] = true;
	for (auto e : graph[song]) _dfs(e);
	result.push_back(song);
}

void generatePlaylist(const vector<playlist>& playlists) {
	for (const auto& p : playlists)
		for (int i = 0; i < p.size() - 1; ++i) {
			graph[p[i]].push_back(p[i + 1]);
			hasParent[p[i + 1]] = true;
		}

	for (int song = 0; song < NUM_SONGS; ++song)
		if (!hasParent[song]) _dfs(song); // this is a root

	std::reverse(result.begin(), result.end());
}


int main() {
	vector<playlist> playlists = {
		{ 1, 7, 3 },
		{ 2, 1, 6, 7, 9 },
		{ 3, 9, 5 }
	};
	generatePlaylist(playlists);
	for (auto e : result) cout << e << " ";
	cout << "\n";
}
