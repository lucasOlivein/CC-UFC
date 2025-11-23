<script>
import { ref } from 'vue';
import { Auth } from '../../stores/user';
import { Ads } from '../../stores/ads';
import router from '../../router';



export default {
    props: {
        userr: Object
    },
    data() {
        return {
            user : ref(this.userr),
            tittle: ref('Atualizar Dados'),
            admin: Auth(),
            ads: Ads(),
            name: null,
            email: null,
            contact: null,
            password: null
        }
    },
    methods: {

        async deleteUser() {
            const res = await this.admin.deleteUser(this.admin.users.value[this.index].id)

            console.log(res)
            if(res.status == '200')
            {
                this.$emit('userDeleted')
            }else{
            console.log(res.message)
            this.$emit("deleteFail", res)
            }

        },
        
        updateUser() {

            if (this.name || this.email || this.contact || this.password) {
                const data = {}
                if (this.name)
                this.user.username = data.username = this.name
                if (this.email)
                this.user.email= data.email = this.email
                if (this.contact)
                this.user.contato = data.contato = this.contact
                if (this.password)
                    data.password = this.password

                const res = this.admin.updateUser(this.user.id, data)
                    this.name = null,
                    this.email = null,
                    this.contact = null,
                    this.password = null

                if(res.status == '200'){
                    this.tittle = Atualizado
                }else{
                    this.tittle = res.message
                }
            } else {
                console.log('nao ha mudancas')
            }

        },
    }
}


</script>


<template>
    <div class="container border">
        <div class="mb-3">
            <h5>{{ tittle }}</h5>
        </div>
        <div class="row">
            <div class="col-9">

                <div class="container border align-text-itens">
                    <div class="row my-2">
                        <label for="userName">Nome de Usuário</label>
                        <input autocomplete="off" type="text" :value="user.username"
                            @input="name = $event.target.value" class="form-control mb-3 mx-2" :id="'userName' + user.id">
                    </div>
                    <div class="row">
                        <label for="userEmail">Email</label>
                        <input autocomplete="off" type="text" :value="this.user.email"
                            @input="email = $event.target.value" class="form-control mb-3 mx-2" :id="'userEmail' + user.id" >
                    </div>
                    <div class="row">
                        <label for="userContact">Contato</label>
                        <input autocomplete="off" type="text" :value="this.user.contato"
                            @input="contact = $event.target.value" class="form-control mb-3 mx-2" :id="'userContact' + user.id">
                    </div>
                    <div class="row">
                        <label for="userPassword">Senha</label>
                        <input autocomplete="off" type="password" class="form-control mb-3 mx-2"
                            @input="password = $event.target.value" :id="'userPassword' + user.id">
                    </div>
                    <div class="" style="text-align: center;">
                        <button type="submit" class="btn btn-primary mt-3 mb-2" @click="updateUser">Atualizar</button>
                    </div>
                </div>

            </div>
            <div class="col-3">
                <button class="btn btn-danger" @click="deleteUser">Deletar</button>
            </div>
        </div>
    </div>
</template>