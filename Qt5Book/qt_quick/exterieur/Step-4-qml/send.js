Qt.include("logs.js")
Qt.include("services.js")
Qt.include("request.js")
Qt.include("receive.js")

function reqWeather(city, days) {
    var params = {
        "q": city,
        "format": "json",
        "extra": "utcDateTime",
        "num_of_days": days,
        "key": token
    };
    main.searching = true;
    sendRequest(services["Weather"], params, recvWeather);
}
