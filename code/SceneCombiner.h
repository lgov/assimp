/*
Open Asset Import Library (ASSIMP)
----------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team
All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the 
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

/** @file Declares a helper class, "SceneCombiner" providing various
 *  utilities to merge scenes.
 */
#ifndef AI_SCENE_COMBINER_H_INC
#define AI_SCENE_COMBINER_H_INC

#include "../include/aiAssert.h"

namespace Assimp	{

// ---------------------------------------------------------------------------
/** \brief Helper data structure for SceneCombiner.
 *
 *  Describes to which node a scene must be attached to.
 */
struct AttachmentInfo
{
	AttachmentInfo()
		:	scene			(NULL)
		,	attachToNode	(NULL)
	{}

	AttachmentInfo(aiScene* _scene, aiNode* _attachToNode)
		:	scene			(_scene)
		,	attachToNode	(_attachToNode)
	{}

	aiScene* scene;
	aiNode*  attachToNode;
};

// ---------------------------------------------------------------------------
/** \brief Static helper class providing various utilities to merge two
 *    scenes. It is intended as internal utility and NOT for use by 
 *    applications.
 * 
 * The class is currently being used by various postprocessing steps
 * and loaders (ie. LWS).
 */
class ASSIMP_API SceneCombiner
{
	// class cannot be instanced
	SceneCombiner() {}

public:

	// -------------------------------------------------------------------
	/** Merges two or more scenes.
	 *
	 *  @param dest Destination scene. Must be empty.
	 *  @param src Non-empty list of scenes to be merged. The function
	 *    deletes the input scenes afterwards.
	 *  @param flags Combination of the AI_INT_MERGE_SCENE flags defined above
	 */
	static void MergeScenes(aiScene* dest,std::vector<aiScene*>& src,
		unsigned int flags = 0);


	// -------------------------------------------------------------------
	/** Merges two or more scenes and attaches all sceenes to a specific
	 *  position in the node graph of the masteer scene.
	 *
	 *  @param dest Destination scene. Must be empty.
	 *  @param master Master scene. It will be deleted afterwards. All 
	 *    other scenes will be inserted in its node graph.
	 *  @param src Non-empty list of scenes to be merged along with their
	 *    corresponding attachment points in the master scene. The function
	 *    deletes the input scenes afterwards.
	 *  @param flags Combination of the AI_INT_MERGE_SCENE flags defined above
	 */
	static void MergeScenes(aiScene* dest, const aiScene* master, 
		std::vector<AttachmentInfo>& src,
		unsigned int flags = 0);


	// -------------------------------------------------------------------
	/** Merges two or more meshes
	 *
	 *  @param dest Destination mesh. Must be empty.
	 *  @param src Non-empty list of meshes to be merged. The function
	 *    deletes the input meshes afterwards.
	 *  @param flags Currently no parameters
	 */
	static void MergeMeshes(aiMesh* dest,std::vector<aiMesh*>& src,
		unsigned int flags);


	// -------------------------------------------------------------------
	/** Add a name prefix to all nodes in a scene.
	 *
	 *  @param Current node. This function is called recursively.
	 *  @param prefix Prefix to be added to all nodes
	 *  @param len STring length
	 */
	static void AddNodePrefixes(aiNode* node, const char* prefix,
		unsigned int len);
};

}

#endif // !! AI_SCENE_COMBINER_H_INC