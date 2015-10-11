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

            Passage(Direction direction, Room &sideA, Room &sideB);

			Direction direction() const;
			Room &sideA() const;
			Room &sideB() const;

        private:
			Direction mDirection;
            Room &mSideA;
            Room &mSideB;
        };
    }
}


#endif //DUNGEONCRAWLER_PASSAGE_H
