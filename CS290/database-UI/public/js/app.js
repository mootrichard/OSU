$(document).ready(function(){

  $(document.body).on('click','#addWorkout', function(){
    //var targetElements = $('#name, #reps, #weight, #units, #date');
    if( $('#name').val() === '' ||
        $('#reps').val() === '' ||
        $('#weight').val() === ''
      ){
        $('form input').not('button').each(function(ind, elem){
          $(elem).parent().removeClass('has-error');
          if($(elem).val() === ''){
            $(elem).parent().addClass('has-error');
          }
        });
      return;
    }
    else {
      var targetElements = $('form :input').not('button'),
          sendData = {
            name: $('#name').val(),
            reps: $('#reps').val(),
            weight: $('#weight').val(),
            units: $('#units').val(),
            date: $('#date').val()
          };

      $.ajax({
        method:"POST",
        url:"add-workout",
        data: sendData
      }).done(function(data){
        $('#workoutTable tr:last').after(data);
      });
    }
  });

  $('#reset').on('click', function(){
    $('form input').not('button').each(function(ind, elem){
      $(elem).val("");
    })
  });

  $(document.body).on('click', '.deleteWorkout', function(){
    var sendId = $(this).parent().parent().children().filter('.hidden')[0];
    var sendData = {};
    sendData.id = $(sendId).text();

    $.ajax({
      method:"DELETE",
      url:"delete-workout",
      data: sendData
    }).done(function(data){
      var selectRow = '#'+data;
      $(selectRow).parent().remove();
    });
  });

  $(document.body).on('click', '.editWorkout', function(){
    var grabRow = $(this).parent().parent().children();
    $(grabRow).each(function(ind, elem){
      if($(elem).hasClass('hidden')){
        return;
      }
      else if ($(elem).hasClass('edit-buttons')) {
        $(elem).children().filter('.editWorkout').removeClass('editWorkout').addClass('updateWorkout').text("Update");
      }
      else if($(elem).hasClass('reps') || $(elem).hasClass('weight')){
        var elementText = $(elem).text();
        if($(elem).hasClass('reps')){
          $(elem).replaceWith("<td class='reps'><div class='form-group'><input type='number' class='form-control' value='" + elementText +"'></div></td>");
        }else{
          $(elem).replaceWith("<td class='weight'><div class='form-group'><input type='number' class='form-control' value='" + elementText +"'></div></td>");
        }
      }
      else if($(elem).hasClass('date')){
        var elementText = $(elem).text();
        $(elem).replaceWith("<td class='date'><div class='form-group'><input type='date' class='form-control' value='" + elementText +"'></div></td>");
      }
      else if($(elem).hasClass('name')){
        var elementText = $(elem).text();
        $(elem).replaceWith("<td class='name'><div class='form-group'><input type='text' class='form-control' value='" + elementText +"'></div></td>");
      }
      else if($(elem).hasClass('units')){
        $(elem).replaceWith("<td class='units'><div class='form-group'><select class='form-control' name='' id='units'><option value='1'>lbs</option><option value='0'>kgs</option></select></div></td>");
      }
    })
  });

  $(document.body).on('click', '.updateWorkout', function(){
    var sendData = {};
    $(this).parent().parent().children().not('.edit-buttons').each(function(ind,elem){
      $(elem).children().removeClass('has-error');
      if($(elem).children().children().val() == ''){
        $(elem).children().addClass('has-error');
      } else {
        if($(elem).attr('class') == 'hidden'){
          sendData.id = $(elem).text();
        } else{
          sendData[$(elem).attr('class')] = $(elem).children().children().val();
        }
      }
    });

    $.ajax({
      method:"POST",
      url:"update-workout",
      data: sendData
    }).done(function(data){
      var selectRow = "tr." + data.id;
      $(selectRow).children().not('.hidden').each(function(ind, elem){
        if ($(elem).hasClass('edit-buttons')) {
          $(elem).children().filter('.updateWorkout').removeClass('updateWorkout').addClass('editWorkout').text("Edit");
        }
        else if($(elem).hasClass('reps') || $(elem).hasClass('weight')){
          var elementText = $(elem).children().children().val();
          if($(elem).hasClass('reps')){
            $(elem).replaceWith("<td class='reps text-center col-md-2'>" + elementText +"</td>");
          }else{
            $(elem).replaceWith("<td class='weight text-center col-md-2'>" + elementText +"</td>");
          }
        }
        else if($(elem).hasClass('date')){
          var elementText = $(elem).children().children().val();
          $(elem).replaceWith("<td class='date text-center'>" + elementText +"</td>");
        }
        else if($(elem).hasClass('name')){
          var elementText = $(elem).children().children().val();
          $(elem).replaceWith("<td class='name'>" + elementText +"</td>");
        }
        else if($(elem).hasClass('units')){
          var elementText = $(elem).children().children().val();
          if(elementText == 1){
            $(elem).replaceWith("<td class='units'>lbs</td>");
          }
          else if(elementText == 0){
            $(elem).replaceWith("<td class='units'>kgs</td>");
          }
        }
      });
    });
  });
});
