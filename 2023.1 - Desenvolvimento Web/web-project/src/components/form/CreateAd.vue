<script>
import axios from 'axios'
import { Auth } from "../../stores/user.js"
import { api } from '../../apiConfig'
import { Ads } from '../../stores/ads.js'

export default {
    data() {
        return {
            estado: "",
            categoria: '',
            fotos: [],
            fotosName: [],
            input: null,
            auth: Auth(),
            tittle: '',
            description: '',
            ads: Ads(),
            preco: 0,
            userId: null,
        }
    },
    methods: {

        requireFields() {
            if (this.tittle != '' && this.estado != '' && this.description != '' && this.categoria != '')
                return true
            else
                return false
        },

        cleanForm() {
            this.$refs.adsSend.click()
            this.tittle = ''
            this.description = ''
            this.preco = ''
            this.estado = ''
            this.categoria = ''
            this.input = null
            this.$refs.fileInput.value = ''
            this.fotos = []
        },
        onSelectFile() {
            this.input = this.$refs.fileInput
            const files = this.input.files

            console.log(this.tittle)
            console.log(this.description)
            const imgs = []
            let self = this;
            if (files) {

                for (let i = 0; i < files.length; i++) {
                    const reader = new FileReader
                    reader.addEventListener("load", function (e) {
                        const readerTarget = e.target;

                        const img = document.createElement('img');
                        img.src = readerTarget.result
                        // img.classList.add('base-image-input')

                        self.fotos.push(img)
                        self.fotosName.push(files[i].name)
                    })

                    reader.readAsDataURL(files[i])
                    this.$emit('input', files[i])
                }
            }
        },

        async addAd() {
            let imageId = null
            let self = this

            if (this.requireFields()) {
                if (this.input) {
                    imageId = await this.ads.uploadImages(this.fotos, this.fotosName, this.auth.token)
                    console.log(imageId)
                }
                const authorization = {
                    headers: {
                        Authorization: `Bearer ${self.auth.token}`,
                    },
                }
                const fields = {
                    user: self.auth.id,
                    data: {
                        tittle: self.tittle,
                        description: self.description,
                        user: self.auth.id,
                        estado: self.estado,
                        categoria: self.categoria,
                        photos: imageId,
                        preco: self.preco
                    }
                }
                const res = this.ads.createAd(fields, authorization)

                if ((await res).status == 200) {
                    this.cleanForm()
                } else {
                    console.log('erro ao enviar o anuncios')
                    this.$refs.failSend.click()
                }

            } else {
                console.log('require fields empty')
                this.$refs.failSend.click()
            }
        },

        deletar(i) {
            this.fotos.splice(i, 1)
            this.fotosName.splice(i, 1)
        }
    }
}
</script>

<template>
    <!--    Formulario para adicionar anuncios -->


    <form>

        <!-- Titulo  -->
        <div class="form-group mb-3 row justify-content-center">
            <label for="titulo">
                <h5>Título</h5>
            </label>
            <div class="col-11 ">
                <input type="text" class="form-control" id="titulo" v-model="tittle">
            </div>
        </div>

        <!-- Descrição -->
        <div class="form-group mb-3 row justify-content-center">
            <label for="exampleFormControlTextarea1" class="float-start">
                <h5>Descrição</h5>
            </label>
            <div class="col-11">
                <textarea class="form-control" type="text" id="exampleFormControlTextarea1" rows="3"
                    v-model="description"></textarea>
            </div>
        </div>


        <!-- Condicao -->
        <div class="row">
            <div class="col-6">
                <label for="categoriaField" class="float-start">
                    <h5>Categoria</h5>
                </label>
                <select id="categoriaField" class="form-select mb-3" aria-label="Default select example"
                    v-model="categoria">
                    <option v-for="(categoria, i) in ads.categorias.value" :value="i + 1"> {{
                        categoria.attributes.name }}</option>

                </select>
            </div>
            <div class="col-6">
                <label for="categoriaField" class="float-start">
                    <h5>Estado</h5>
                </label>
                <select id="estadoField" class="form-select mb-3" placeholder="Estado" aria-label="Default select example"
                    v-model="estado">
                    <option value="Novo">Novo</option>
                    <option value="Usado em estado novo">Usado em estado novo</option>
                    <option value="Usado em boas condições">Usado em boas condições</option>
                    <option value="Usado em condições razoaveis">Usado em condições razoaveis</option>
                </select>
            </div>
        </div>

        <div class="row">
            <div class="col-5 ms-1 mb-3">
                <label for="precoField" class="float-start">
                    <h5>Preço</h5>
                </label>
                <input type="number" class="form-control" id="precoField" v-model="preco">
            </div>
            <div class="col-5" v-if="auth.role == 'Admin'">
                <label for="userField" class="float-start">
                    <h5>Usuário</h5>
                </label>
                <select id="userField" class="form-select mb-3" aria-label="Default select example" v-model="userId">
                    <option v-for="(user, i) in auth.anuncios.value" :value="user.id"> {{
                        user.username }}</option>

                </select>
            </div>
        </div>


        <div class="mb-3">
            <label for="fotosField" class="float-start">
                <h5 class="mx-2">Fotos</h5>
            </label>
            <input multiple id="fotosField" class="d-grid gap-2 d-md-block" ref="fileInput" type="file"
                @input="onSelectFile">
        </div>




        <button class="btn btn-outline-secondary" @click.prevent="addAd()">Enviar</button>

        <div class="container text-center">
            <div class="row align-items-center">
                <div v-if="fotos" v-for="(foto, i) in fotos" class="col-6 my-3" :key="i">
                    <img :src="foto.src" alt="" class="img-fluid img-thumbnail" id="tam">
                    <button class="btn" @click.prevent="deletar(i)"><svg xmlns="http://www.w3.org/2000/svg" width="16"
                            height="16" fill="currentColor" class="bi bi-trash3-fill" viewBox="0 0 16 16">
                            <path
                                d="M11 1.5v1h3.5a.5.5 0 0 1 0 1h-.538l-.853 10.66A2 2 0 0 1 11.115 16h-6.23a2 2 0 0 1-1.994-1.84L2.038 3.5H1.5a.5.5 0 0 1 0-1H5v-1A1.5 1.5 0 0 1 6.5 0h3A1.5 1.5 0 0 1 11 1.5Zm-5 0v1h4v-1a.5.5 0 0 0-.5-.5h-3a.5.5 0 0 0-.5.5ZM4.5 5.029l.5 8.5a.5.5 0 1 0 .998-.06l-.5-8.5a.5.5 0 1 0-.998.06Zm6.53-.528a.5.5 0 0 0-.528.47l-.5 8.5a.5.5 0 0 0 .998.058l.5-8.5a.5.5 0 0 0-.47-.528ZM8 4.5a.5.5 0 0 0-.5.5v8.5a.5.5 0 0 0 1 0V5a.5.5 0 0 0-.5-.5Z" />
                        </svg></button>
                </div>
            </div>
        </div>

    </form>
    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#adsSend" ref="adsSend"
        style="display: none;"></button>

    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#sendAdsFail" ref="failSend"
        style="display: none;"></button>
</template>

<style></style>