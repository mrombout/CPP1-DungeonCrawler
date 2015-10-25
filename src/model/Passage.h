#ifndef DUNGEONCRAWLER_PASSAGE_H
#define DUNGEONCRAWLER_PASSAGE_H

namespace dc {
    namespace model {
        class Room;
    }
}

namespace dc {
    namespace model {
        class Passage {
        public:
			enum Direction {
				North,
				East,
				South,
				West,
				Unknown
			};

            Passage(Room &sideA, Room &sideB);

			Room &sideA() const;
			Room &sideB() const;

            Room &otherSide(const Room &room) const;

        private:
            Room &mSideA;
            Room &mSideB;
        };
    }
}

#endif //DUNGEONCRAWLER_PASSAGE_H
