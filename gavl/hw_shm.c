/*****************************************************************
 * gavl - a general purpose audio/video processing library
 *
 * Copyright (c) 2001 - 2012 Members of the Gmerlin project
 * gmerlin-general@lists.sourceforge.net
 * http://gmerlin.sourceforge.net
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * *****************************************************************/

#include <stdlib.h>

#include <gavl/gavl.h>
#include <hw_private.h>
#include <hw_shm.h>

#include <gavlshm.h>

typedef struct
  {
  gavl_shm_pool_t * pool;
  int shm_size;
  } shm_t;

/* Functions */
static void destroy_native_shm(void * native)
  {
  shm_t * s = native;
  free(s);
  }

static gavl_pixelformat_t * get_image_formats_shm(gavl_hw_context_t * ctx)
  {
  int i;
  gavl_pixelformat_t * pixelformats;
  int num_image_formats = gavl_num_pixelformats();
  pixelformats = calloc(num_image_formats+1, sizeof(*pixelformats));

  for(i = 0; i < num_image_formats; i++)
    pixelformats[i] = gavl_get_pixelformat(i);
  
  pixelformats[num_image_formats] = GAVL_PIXELFORMAT_NONE;
  return pixelformats;
  }

static gavl_pixelformat_t * get_overlay_formats_shm(gavl_hw_context_t * ctx)
  {
  int i;
  gavl_pixelformat_t * pixelformats;
  int idx = 0;
  int num_image_formats = gavl_num_pixelformats();

  pixelformats = calloc(num_image_formats+1, sizeof(*pixelformats));
  
  for(i = 0; i < num_image_formats; i++)
    {
    gavl_pixelformat_t p = gavl_get_pixelformat(i);
    
    if(gavl_pixelformat_has_alpha(p))
      {
      pixelformats[idx] = p;
      idx++;
      }
    }
  pixelformats[idx] = GAVL_PIXELFORMAT_NONE;
  return pixelformats;
  }


#if 0
static void video_format_adjust_shm(gavl_hw_context_t * ctx,
                                    gavl_video_format_t * fmt)
  {
  
  }

static void overlay_format_adjust_shm(gavl_hw_context_t * ctx,
                                      gavl_video_format_t * fmt)
  {
  
  }
#endif

static gavl_video_frame_t * video_frame_create_hw_shm(gavl_hw_context_t * ctx,
                                                      gavl_video_format_t * fmt)
  {
  gavl_video_frame_t * ret = gavl_video_frame_create(NULL);
  
  return ret;
  }

static void video_frame_destroy_shm(gavl_video_frame_t * f)
  {
  
  }

typedef struct
  {
  int pid;
  int id;
  } shm_packet_info;

static void video_frame_to_packet_shm(gavl_hw_context_t * ctx,
                                      const gavl_video_format_t * fmt,
                                      gavl_video_frame_t * frame,
                                      gavl_packet_t * p)
  {
  
  }

static void video_frame_from_packet_shm(gavl_hw_context_t * ctx,
                                        const gavl_video_format_t * fmt,
                                        gavl_packet_t * p,
                                        gavl_video_frame_t * frame)
  {
  
  }

static const gavl_hw_funcs_t funcs =
  {
   .destroy_native         = destroy_native_shm,
   .get_image_formats      = get_image_formats_shm,
   .get_overlay_formats    = get_overlay_formats_shm,
   .video_frame_create_hw  = video_frame_create_hw_shm,
   .video_frame_destroy    = video_frame_destroy_shm,
   .video_frame_to_packet = video_frame_to_packet_shm,
   .video_frame_from_packet   = video_frame_from_packet_shm,
   
   //   .video_format_adjust    = video_format_adjust_shm,
   //   .overlay_format_adjust  = overlay_format_adjust_shm,
  };


gavl_hw_context_t * gavl_hw_ctx_create_shm()
  {
  shm_t * native = calloc(1, sizeof(*native));
  return gavl_hw_context_create_internal(native, &funcs, GAVL_HW_SHM, GAVL_HW_SUPPORTS_VIDEO | GAVL_HW_SUPPORTS_SHARED);
  }



/*
  
struct gavl_hw_context_s
  {
  void * native;
  gavl_hw_type_t type;
  const gavl_hw_funcs_t * funcs;
  gavl_pixelformat_t * image_formats;
  gavl_pixelformat_t * overlay_formats;
  };

  
gavl_hw_context_t *
gavl_hw_context_create_internal(void * native,
                                const gavl_hw_funcs_t * funcs,
                                gavl_hw_type_t type);

void 
gavl_hw_destroy_video_frame(gavl_hw_context_t * ctx,
                            gavl_video_frame_t * frame);
*/
