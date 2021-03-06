/*

             *
            ***
           *****
   *********************       Mercenaries Engineering SARL
     *****************              Copyright (C) 2016
       *************
         *********        http://www.mercenaries-engineering.com
        ***********
       ****     ****
      **           **

*/

#pragma once

#include <map>
#include <ImfPixelType.h>
#include "Mask.h"

namespace openexrid
{

// This class is used during the rendering of the image to accumulate
// the coverage data and then build a Mask object.
class Builder
{
	friend class Mask;
public:

	// Initialize a builder
	Builder (int width, int height, const std::vector<std::string> &slices);

	// Add some coverage in the pixel (x,y) for the object named objectName.
	// The sum of the coverage of a pixel is supposed to be between [0, 1].
	// This method is not thread safe.
	void addCoverage (int x, int y, uint32_t id, const float *sliceValues);

private:

	// The image resolution.
	int	_Width, _Height;

	// The sample list per pixel.
	std::vector<SampleList>	_Pixels;

	std::vector<std::string>	_Slices;
};

}
