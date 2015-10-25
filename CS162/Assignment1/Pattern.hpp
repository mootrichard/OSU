#ifndef PATTERNS_HPP
#define PATTERNS_HPP

class Pattern {
	private:
		int xOffset;
		int yOffset;
	public:
		Glider( int x , int y );
		Blinker( int x , int y );
		Gun( int x , int y );
};

#endif // PATTERNS_HPP