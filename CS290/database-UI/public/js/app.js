$(document).ready(function(){
  $('#workoutTable').editableTableWidget({disableClass: "edit-disabled", cloneProperties: []});

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
      console.log(sendData);

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
    console.log($(this).parent().parent().children().not('.edit-disabled'));
    var sendId = $(this).parent().parent().children().filter('.hidden')[0];
    var sendData = {};
    sendData.id = $(sendId).text();
    console.log(sendData);

    $.ajax({
      method:"DELETE",
      url:"delete-workout",
      data: sendData
    }).done(function(data){
      console.log(data);
      var selectRow = '#'+data;
      $(selectRow).parent().remove();
    });
  });
});
