import QtQuick 2.15
import QtQuick.Controls 2.15
import QtReforce.Meta.Network 0.0
import "qrc:/QMetaUI/Form/Core"
import "qrc:/QMetaUI/Form/Basic"

MCFormControlItem {
    id: control

    property string source:""

    MURequestModel {
        id: request

        onRequestStart:{
            control.requestStarted()
        }

        onRequestSuccess:{
//            control.model=Qt.binding(function(){return request.model})
//            control.count=request.model.rowCount()
//            control.isEmpty=(request.count===0)
//            control.requestSuccess()
        }

        onRequestFinished: {
//            control.requestFinished()
        }

        onRequestFail: {
//            snackBar.showError(message)
//            control.requestError(message)
        }

        onRequestUnauthorized: {
//            snackBar.showError(message)
//            control.requestError(message)
        }
        onRequestError: {
//            snackBar.showError(message)
//            control.requestError(message)
        }

    }

}
