class HouseOfSantaClaus
{
private:
	int  m_count;
	int* m_solutions;

public:
	// c'tor / d'tor
	HouseOfSantaClaus();
	virtual ~HouseOfSantaClaus();

	// public interface
	virtual void Solve() = 0;
	int NumberOfSolutions() { return m_count; }

protected:
	void AddSolution(int number);

private:
	// private helper method
	void PrintSolution(ostream& os, int number) const;

	// output
	friend ostream& operator<< (ostream&, const HouseOfSantaClaus&);
};

class HouseOfSantaClausIterative : public HouseOfSantaClaus
{
private:
	static const int Min = 111111111;
	static const int Max = 155555552;

	int m_digits[9];

public:
	// c'tor
	HouseOfSantaClausIterative();

public:
	// public interface
	void Solve();

private:
	// private helper methods
	bool IsSolution(int number);
	bool CheckValidRangeOfDigits();
	bool CheckValidSequenceOfDigits();
	bool CheckValidEdges();
	bool CheckForDuplicateEdges();
	void NumberToDigits(int number);
};

class HouseOfSantaClausRecursive : public HouseOfSantaClaus
{
private:
	static const int MaxNodes = 5;
	static const int MaxEdges = 8;

	static bool m_adjacent[MaxNodes][MaxNodes];  // adjacency matrix
	bool  m_painted[MaxNodes][MaxNodes];         // painted edges

	// constructing a single path
	int m_currentPath;   // current solution
	int m_paintedEdges;  // edges so far painted

public:
	// c'tor
	HouseOfSantaClausRecursive();

public:
	// public interface
	void Solve();

private:
	// private helper methods
	void PaintEdge(int from, int to);
	void ClearEdge(int from, int to);
	void TryPaintingEdge(int from);
};
