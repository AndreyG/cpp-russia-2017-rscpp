#include "analogliterals.hpp"

#include <cassert>

int main()
{
  using namespace analog_literals::symbols;

    // ReSharper disable once CppPossiblyUnintendedObjectSlicing
  assert( ( o-------------o
            |L             \
            | L             \
            |  L             \
            |   o-------------o
            |   !             !
            !   !             !
            o   |             !
             L  |             !
              L |             !
               L|             !
                o-------------o ).volume == ( o-------------o
                                              |             !
                                              !             !
                                              !             !
                                              o-------------o ).area * int(I-------------I) );

  // ReSharper disable once CppPossiblyUnintendedObjectSlicing
  assert( top( o-------o
               |L       \
               | L       \
               |  o-------o
               |  !       !
               !  !       !
               o  |       !
                L |       !
                 L|       !
                  o-------o ) == ( o-------o
                                   |       !
                                   !       !
                                   o-------o ) );
}
