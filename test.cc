#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "card.h"
#include "card-storage.h"

#include <sstream>

std::string cardRepresentation(const Card &card) {
	std::stringstream ss;
	ss << card;
	return ss.str();
}

std::string freeCellRepresentation(const FreeCell &fc) {
	std::stringstream ss;
	ss << fc;
	return ss.str();
}

TEST_CASE( "Card construction and printing tests", "[card]" ) {
	REQUIRE(cardRepresentation({Color::Heart, 1}) == "1h");
	REQUIRE(cardRepresentation({Color::Heart, 2}) == "2h");
	REQUIRE(cardRepresentation({Color::Heart, 3}) == "3h");
	REQUIRE(cardRepresentation({Color::Heart, 4}) == "4h");
	REQUIRE(cardRepresentation({Color::Heart, 5}) == "5h");
	REQUIRE(cardRepresentation({Color::Heart, 6}) == "6h");
	REQUIRE(cardRepresentation({Color::Heart, 7}) == "7h");
	REQUIRE(cardRepresentation({Color::Heart, 8}) == "8h");
	REQUIRE(cardRepresentation({Color::Heart, 9}) == "9h");
	REQUIRE(cardRepresentation({Color::Heart, 10}) == "10h");
	REQUIRE(cardRepresentation({Color::Heart, 11}) == "Jh");
	REQUIRE(cardRepresentation({Color::Heart, 12}) == "Qh");
	REQUIRE(cardRepresentation({Color::Heart, 13}) == "Kh");

	REQUIRE(cardRepresentation({Color::Diamond, 7}) == "7d");
	REQUIRE(cardRepresentation({Color::Club, 7}) == "7c");
	REQUIRE(cardRepresentation({Color::Spade, 7}) == "7s");
}

TEST_CASE( "FreeCell operations", "[freecell]" ) {
    FreeCell free_cell;
	REQUIRE(freeCellRepresentation(free_cell) == "_");

	REQUIRE(free_cell.topCard() == nullptr);
	REQUIRE(free_cell.getCard() == nullptr);

	auto c = std::make_unique<Card>(Color::Heart, 1);
	REQUIRE(free_cell.canAccept(*c));
	REQUIRE(free_cell.acceptCard(std::move(c)));

	REQUIRE(freeCellRepresentation(free_cell) == "1h");
	REQUIRE(cardRepresentation(*free_cell.topCard()) == "1h");
	REQUIRE(cardRepresentation(*free_cell.getCard()) == "1h");

	REQUIRE(freeCellRepresentation(free_cell) == "_");
}
