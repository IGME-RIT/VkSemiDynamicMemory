In previous tutorials, we had to manually delete all
BufferCPUs for Meshes and Textures, after they were copied
to the GPU. 

In this tutorial, we have a system that automatically 
deletes them for us. BufferGPU and TextureGPU
will now save BufferCPU pointers that are queued for copy,
and then Demo.cpp will call ClearCacheCPU to erase all 
queued CPU buffers after they are copied to GPU.

Also, Demo::prepare_descriptor_pool() was changed to have
512 of each type of descriptor, and 512 descriptor sets.
These were limited in earlier tutorials, which
confirmed that there were no leaks. We can remove the 
restriction because the code is proven to be stable.

The majority of Microsoft DirectX 12 tutorials set the
limit to 512 and beyond, even when they are only drawing
a triangle or a cube. RAM and VRAM usage does not increase
when the limit is raised, only when you use Vulkakn to make more buffers. 

\You can see for youself by checking RAM and VRAM usage 
when the limit is 16, 512, 2048, etc