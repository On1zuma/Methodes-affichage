
jQuery(function(){                    
  $('#scroll_to_top').css('transition','visibility 0s, opacity 0.5s linear');
  $('#scroll_to_top').css('visibility','hidden');
  $('#scroll_to_top').css('opacity','0')
      $(function () {
          $(window).scroll(function () {
              if ($(this).scrollTop() > 200 ) { 
                  $('#scroll_to_top').css('right','17px');
                  $('#scroll_to_top').css('visibility','visible');
                  $('#scroll_to_top').css('opacity','0.8');
                  $('#scroll_to_top').css('transition','visibility 0s, opacity 0.5s linear');
              } else { 
                //  $('#scroll_to_top').css('display','none');
                      $('#scroll_to_top').css('transition','visibility 0s, opacity 0.5s linear');
                      $('#scroll_to_top').css('visibility','hidden');
                      $('#scroll_to_top').css('opacity','0');
              }
          });
      });
  });
