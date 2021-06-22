import 'package:flutter/material.dart';

class CustomField extends StatefulWidget {
  final Icon? suffix;
  final String? label;
  final TextInputType textType;
  final String? Function(String?)? validator;
  final int? maxLines;
  final String? prefixLabel;
  final String? sufixLabel;
  final int minLines;
  final TextEditingController controller;
  CustomField(
      {Key? key,
      this.label,
      this.suffix,
      required this.controller,
      this.maxLines,
      this.minLines = 1,
      this.textType = TextInputType.name,
      this.validator,
      this.prefixLabel,
      this.sufixLabel})
      : super(key: key);

  @override
  _CustomFieldState createState() => _CustomFieldState();
}

class _CustomFieldState extends State<CustomField> {
  @override
  Widget build(BuildContext context) {
    return TextFormField(
      keyboardType: widget.textType,
      validator: widget.validator,
      maxLines: widget.maxLines,
      controller: widget.controller,
      decoration: InputDecoration(
        labelText: widget.label,
        prefixText: widget.prefixLabel,
        suffixText: widget.sufixLabel,
        // suffixIcon: Icon(
        //   Icons.help,
        // ),

        fillColor: Colors.white,
        filled: true,
        suffix: widget.suffix,
        labelStyle: TextStyle(
          background: Paint()
            ..color = Colors.white
            ..strokeWidth = 20
            ..style = PaintingStyle.stroke
            ..strokeCap = StrokeCap.round
            ..strokeJoin = StrokeJoin.round,
          color: Colors.black,
        ),

        focusedBorder: OutlineInputBorder(
          borderSide: BorderSide(color: Colors.black),
          borderRadius: BorderRadius.circular(20),
        ),
        enabledBorder: OutlineInputBorder(
          borderSide: BorderSide.none,
          borderRadius: BorderRadius.circular(20),
        ),
        border: OutlineInputBorder(
          borderSide: BorderSide.none,
          borderRadius: BorderRadius.circular(20),
        ),
        errorBorder: OutlineInputBorder(
            borderRadius: BorderRadius.circular(20),
            borderSide: BorderSide(color: Colors.red, width: 4)),
      ),
    );
  }
}

class Exemplo extends StatefulWidget {
  // QuartaProduto({Key? key, required this.produtoSendoCadastrado})
  //     : super(key: key);

  @override
  _ExemploState createState() => _ExemploState();
}

class _ExemploState extends State<Exemplo> {
  TextEditingController exemploController = TextEditingController();
  TextEditingController exemploController2 = TextEditingController();
  TextEditingController exemploController3 = TextEditingController();
  TextEditingController exemploController4 = TextEditingController();
  TextEditingController exemploController5 = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Center(
            child: SingleChildScrollView(
      child: Container(
        child: Column(
          children: [
            Container(
                height: 30,
                width: MediaQuery.of(context).size.width * 0.8,
                child: CustomField(
                  sufixLabel: "items",
                  label: 'Quantidade',
                  controller: exemploController,
                )),
            SizedBox(
              height: 15,
            ),
            Container(
                height: 30,
                width: MediaQuery.of(context).size.width * 0.8,
                child: CustomField(
                  label: "Preço",
                  prefixLabel: "R\$",
                  controller: exemploController2,
                )),
            SizedBox(
              height: 15,
            ),
            Container(
                height: 100,
                width: MediaQuery.of(context).size.width * 0.8,
                child: CustomField(
                  label: "Descrição",
                  maxLines: 10,
                  controller: exemploController3,
                )),
            SizedBox(
              height: 15,
            ),
            Container(
                height: 30,
                width: MediaQuery.of(context).size.width * 0.6,
                child: CustomField(
                  suffix: Icon(Icons.person),
                  label: "Usuario",
                  controller: exemploController4,
                )),
            SizedBox(
              height: 15,
            ),
            Container(
                height: 30,
                width: MediaQuery.of(context).size.width * 0.8,
                child: CustomField(
                  label: "Texto",
                  validator: (value) {
                    if (value == null) {
                      return "Digite um valor";
                    }
                    return null;
                  },
                  controller: exemploController5,
                )),
          ],
        ),
      ),
    )));
  }
}
