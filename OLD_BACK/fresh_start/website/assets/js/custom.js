
$(document).ready(function () {
    (function () {
        $('.sidenav').sidenav();
        $('.button-collapse').sidenav();
        // $('select').select2();
        $('.modal').modal({
            dismissible: false
        });
    }());

});
document.addEventListener("DOMContentLoaded", function () {
    hideLoader();
});


function setCookie(cname, cvalue, mins) {
    var d = new Date();
    cvalue = cvalue || "";
    mins = mins || 60;
    d.setTime(d.getTime() + (mins * 60 * 1000));
    var expires = "expires=" + d.toUTCString();
    document.cookie = cname + "=" + cvalue + ";path=/; " + expires;
    return cname + "=" + cvalue + ";path=/; " + expires;
}
function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for (var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) === ' ')
            c = c.substring(1);
        if (c.indexOf(name) === 0)
            return decodeURIComponent(c.substring(name.length, c.length));
    }
    return "";
}
function deleteCookie(name) {
    setCookie(name, "", -1000)
    document.cookie = name + '=; path=/; expires=Thu, 01 Jan 1970 00:00:01 GMT;';
    return getCookie(name);
}
function htmlEncode(value) {
    return $('<div/>').text(value).html();
}
function htmlDecode(value) {
    return $('<div/>').html(value).text();
}
function getEpochTime() {
    return (new Date).getTime();
}
function setSideNavActive(id) {
    document.getElementById(id).className += " active-side-nav";
}
function hideLoader() {
    $('.default-loader').delay(1000).fadeOut('slow');
}
function showLoader() {
    $('.default-loader').fadeIn();
}