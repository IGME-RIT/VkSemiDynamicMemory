In previous tutorials, we had to manually delete all
BufferCPUs for Meshes and Textures, but now we have a
system that deletes that for us. BufferGPU and TextureGPU
will now save BufferCPU pointers that are queued for copy,
and then Demo.cpp will call ClearCacheCPU to erase all 
queued CPU buffers after they are copied to GPU

Also changed Demo::prepare_descriptor_pool() to have
512 of each type of descriptor, and 512 descriptor sets.
Earlier tutorials limited this number as a way of
confirming that there were no leaks, but now that the 
code is stable, we can remove the restriction