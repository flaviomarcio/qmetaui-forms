import QtQuick 2.14

MCFormControlItem {
    id: control

    //auto create Component in private Loader
    property bool autoLoad: true

    //source to load in private Loader
    property string source: ''

    //sourceComponent to load in private Loader
    property var sourceComponent: undefined

    //loaded created component in Loader
    property MCFormControlItem form: loader.item

    //return control state loaded
    readonly property bool isLoaded: loader.isLoaded

    signal show()
    signal reset()
    signal refresh()
    signal update()
    signal close()

    signal load()
    signal loaded(var form)

    signal unLoad()
    signal unLoaded()

    onLoad: {
        if((control.sourceComponent !== undefined) && (control.sourceComponent !== null)){
            loader.sourceComponent=control.sourceComponent
            return;
        }

        if(String(control.source).trim() !== ''){
            loader.source = control.source
            return;
        }

        loader.free()
    }

    onUnLoad: {
        control.visible=false
        loader.free()
    }

    Loader {
        id: loader

        //return control state loaded
        property bool isLoaded: false

        function free(){
            loader.sourceComponent = undefined
        }

        onStatusChanged: {
            if(loader.status===Loader.Ready){
                control.visible = false
                control.form = loader.item
                control.form.parent = control.parent
                connection.target = form
                control.loaded(form)
                isLoaded=true
                return;
            }

            if(loader.status===Loader.Null){
                connection.target = null
                control.unloaded()
                isLoaded=false
                return;
            }
        }

        Connections {
            id: connection
            target: null
            function onShow(){
                control.show()
            }
            function onClose(){
                control.close()
            }
            function onObjectReload(){
                control.objectReload()
            }
            function onDataNew(data){
                control.dataNew(data)
            }
            function onDataSearch(data){
                control.dataSearch(data)
            }
            function onDataEdit(data){
                control.dataEdit(data)
            }
            function onDataRemove(data){
                control.dataRemove(data)
            }
            function onDataPost(data){
                control.dataPost(data)
            }
            function onDataClear(data){
                control.dataClear(data)
            }
        }
    }
    Component.onCompleted: {
        if(autoLoad)
            control.load()
    }
}


