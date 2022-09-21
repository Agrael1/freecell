#ifndef SEARCH_INTERFACE_H
#define SEARCH_INTERFACE_H

#include "move.h"
#include "game.h"

#include <ostream>

class SearchState;

class SearchAction {
public:
	SearchAction(Location from, Location to) : from_(from), to_(to) {} ;
	SearchState execute(const SearchState& state) const ;

    friend std::ostream& operator<< (std::ostream& os, const SearchAction & action) ;
private:
	Location from_;
	Location to_;
};

class SearchState {
public:
	SearchState(GameState state) : state_(state) {}
	bool isFinal() const;
	std::vector<SearchAction> actions() const;

	bool execute(Location from, Location to);

    friend std::ostream& operator<< (std::ostream& os, const SearchState & state) ;
private:
	void runSafeMoves_();
	GameState state_;
};

class SearchStrategyItf {
public:
	virtual std::vector<SearchAction> solve(const SearchState &init_state) =0 ;
	virtual ~SearchStrategyItf() {}
};

#endif
